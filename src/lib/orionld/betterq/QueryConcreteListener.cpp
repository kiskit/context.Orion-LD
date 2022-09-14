#include <cstring>

#include "antlr4-runtime.h"
#include "QueryParser.h"
#include "QueryConcreteListener.h"
#include "orionld/q/qVariableFix.h"
#include "common/globals.h"
#include "orionld/q/qRelease.h"

/* this class is both the listener and the error listener for the query grammar.
 * It takes the elements the parser gives it and stores them accordingly into a stack.
 * In some places, some stack handling is needed so that a valid, standard and logical QNode structure can be produced.
 */


// this macro should not be needed but there is an issue with ANTLR's management of exceptions
// and since we can't throw them, we need a way to not go on with parsing when there is a semantic error
#define CHECK_FAIL() \
    if (isFailed)    \
        return;
using namespace std;


QNode *QueryConcreteListener::getNode() {
    if (isFailed) {
        // TODO release nodes?
        if (result != nullptr)
            qRelease(result);
        return nullptr;
    } else
        return result;
}


inline QNode *removeParenthesis(QNode *term) {
    if (term->type == QNodeOpen) {
        return term->value.children;
    } else {
        return term;
    }
}

QNode *popAndRemove(std::vector<QNode *> &stack) {
    QNode *back = stack.back();
    stack.pop_back();
    return back;
}

void invertStack(vector<QNode *> &toInvert, vector<QNode *> &invertInto, bool inQuery) {
    // In the case of protect operators, we need to invert all
    // In the other case, we stop at opening par
    while (!toInvert.empty()) {
        if (toInvert.back()->type == QNodeOpen) {
            if (inQuery) {
                toInvert.back()->value.children = popAndRemove(invertInto);
            } else {
                break; // stop inverting
            }
        }
        invertInto.push_back(popAndRemove(toInvert));
    }
}

void QueryConcreteListener::exitQuery(QueryParser::QueryContext *ctx) {
    CHECK_FAIL()
    std::vector<QNode *> queryTermOrTermAssocStack;
    invertStack(stack, queryTermOrTermAssocStack, true);
    if (queryTermOrTermAssocStack.size() > 1) {
        // because there could be only one term, in which case it needs to be left alone
        std::vector<QNode *> orStack;
        processLogicalAndNodes(queryTermOrTermAssocStack, orStack);
        processLogicalOrNodes(orStack);
    } else {
        stack.push_back(popAndRemove(queryTermOrTermAssocStack));
    }
    result = removeParenthesis(stack.back());
    // Note: the result could be optimized by flattening the QNode structure:
    // A QNodeAnd N1 that has another QNodeAnd N2 as a child can simply add N2's children to its own.
    // Same with QNodeOr nodes
}

void
QueryConcreteListener::processLogicalAndNodes(vector<QNode *> &queryTermOrTermAssocStack,
                                              vector<QNode *> &orStack) const {
    QNode *leftNode = popAndRemove(queryTermOrTermAssocStack);
    QNode **andLastChild = nullptr; // this is needed so we add a QNodeAnd child at the end of the list, thus respecting the input's order

    while (!queryTermOrTermAssocStack.empty()) {
        QNode *middleNode = popAndRemove(queryTermOrTermAssocStack);
        if (middleNode->type == QNodeOr) {
            andLastChild = nullptr;
            orStack.push_back(removeParenthesis(leftNode));
            // TODO: memory leak
            // qRelease(middleNode);
            leftNode = popAndRemove(queryTermOrTermAssocStack);
        } else if (middleNode->type == QNodeAnd) {
            if (leftNode->type == QNodeAnd) {
                QNode *rightNode = removeParenthesis(popAndRemove(queryTermOrTermAssocStack));
                *andLastChild = rightNode;
                andLastChild = &((*andLastChild)->next);
                // TODO: memory leak
                //qRelease(middleNode);
            } else {
                if (andLastChild == nullptr) {
                    andLastChild = &middleNode->value.children;
                }
                *andLastChild = removeParenthesis(leftNode);
                andLastChild = &((*andLastChild)->next);
                leftNode = middleNode;
            }
        } else {
            middleNode = removeParenthesis(middleNode);
            *andLastChild = middleNode;
            andLastChild = &((*andLastChild)->next);
        }
    }
    orStack.push_back(removeParenthesis(leftNode));
}


void QueryConcreteListener::exitQuerytermassoc(QueryParser::QuerytermassocContext *ctx) {
    CHECK_FAIL()
    if (stack.size() > 2) { // meaning we have more than "(queryTerm)". If we don't, we leave it on the stack
        std::vector<QNode *> queryTermStack;
        std::vector<QNode *> orStack;
        invertStack(stack, queryTermStack, false);
        processLogicalAndNodes(queryTermStack, orStack);
        processLogicalOrNodes(orStack);
    }
}

void QueryConcreteListener::processLogicalOrNodes(vector<QNode *> &orStack) {
    if (orStack.size() > 1) {
        auto orNode = qNode(QNodeOr);
        while (!orStack.empty()) {
            auto orOperand = popAndRemove(orStack);
            orOperand->next = orNode->value.children;
            orNode->value.children = orOperand;
        }
        stack.push_back(orNode);
    } else {
        stack.push_back(popAndRemove(orStack));
    }
}

void QueryConcreteListener::exitQueryterm(QueryParser::QuerytermContext *ctx) {
    CHECK_FAIL()
    // This is meant to look at the last 3 terms of this query term. Any other stuff already in the stack will make it fail.
    // The most obvious fail will happen if the current queryterm is a single attribute with no operator following and
    // something (other query terms) is already in the stack
    auto rightNode = popAndRemove(stack);

    if (stack.size() == 0) {
        QNode *term = qNode(QNodeExists);
        term->value.children = rightNode;
        stack.push_back(term);
    } else {
        QNode *opNode, *leftNode;
        switch (stack.back()->type) {
            case QNodeEQ:
            case QNodeNE:
            case QNodeMatch:
            case QNodeNoMatch:
            case QNodeGE:
            case QNodeGT:
            case QNodeLE:
            case QNodeLT:
                opNode = popAndRemove(stack);
                leftNode = popAndRemove(stack);
                opNode->value.children = leftNode;
                leftNode->next = rightNode;
                stack.push_back(opNode);
                break;
            default:
                QNode *term = qNode(QNodeExists);
                term->value.children = rightNode;
                stack.push_back(term);
                break;
        }
    }
}

void QueryConcreteListener::exitAttribute(QueryParser::AttributeContext *ctx) {
    QNode *node = qNode(QNodeVariable);
    bool isMd;
    char *detailsP;
    // TODO memory leak on strdup
    if (qToDbModel) {
        node->value.s = qVariableFix(strdup(ctx->getText().c_str()), forDB, &isMd, &detailsP);
    }
    stack.push_back(node);
}

void QueryConcreteListener::exitPatternop(QueryParser::PatternopContext *ctx) {
    stack.push_back(qNode(QNodeMatch));
}

void QueryConcreteListener::exitPatternnoop(QueryParser::PatternnoopContext *ctx) {
    stack.push_back(qNode(QNodeNoMatch));
}

void QueryConcreteListener::exitGreatereq(QueryParser::GreatereqContext *ctx) {
    stack.push_back(qNode(QNodeGE));
}

void QueryConcreteListener::exitGreater(QueryParser::GreaterContext *ctx) {
    stack.push_back(qNode(QNodeGT));
}

void QueryConcreteListener::exitLess(QueryParser::LessContext *ctx) {
    stack.push_back(qNode(QNodeLT));
}

void QueryConcreteListener::exitLesseq(QueryParser::LesseqContext *ctx) {
    stack.push_back(qNode(QNodeLE));
}

void QueryConcreteListener::exitEqual(QueryParser::EqualContext *ctx) {
    stack.push_back(qNode(QNodeEQ));
}

void QueryConcreteListener::exitUnequal(QueryParser::UnequalContext *ctx) {
    stack.push_back(qNode(QNodeNE));
}

void QueryConcreteListener::exitOrop(QueryParser::OropContext *ctx) {
    stack.push_back(qNode(QNodeOr));
}

void QueryConcreteListener::exitAndop(QueryParser::AndopContext *ctx) {
    stack.push_back(qNode(QNodeAnd));
}

void QueryConcreteListener::exitQuotedstr(QueryParser::QuotedstrContext *ctx) {
    QNode *node = qNode(QNodeStringValue);
    // TODO memory leak
    char *result = strdup(ctx->getText().c_str() + 1);
    result[strlen(result) - 1] = 0;
    node->value.s = result;
    stack.push_back(node);
}

void QueryConcreteListener::exitDatetime(QueryParser::DatetimeContext *ctx) {
    QNode *node;
    if (timestampToFloat) {
        node = qNode(QNodeFloatValue);
        node->value.f = parse8601Time(const_cast<char *>(ctx->getText().c_str()));
    } else {
        node = qNode(QNodeStringValue);
        // TODO memory leak
        node->value.s = strdup(ctx->getText().c_str());
    }
    stack.push_back(node);
}

void QueryConcreteListener::exitDate(QueryParser::DateContext *ctx) {
    QNode *node;
    if (timestampToFloat) {
        node = qNode(QNodeFloatValue);
        // TODO change parsetime signature to add const
        node->value.f = parse8601Time(const_cast<char *>(ctx->getText().c_str()));
    } else {
        node = qNode(QNodeStringValue);
        // TODO memory leak
        node->value.s = strdup(ctx->getText().c_str());
    }
    stack.push_back(node);
}

void QueryConcreteListener::exitTime(QueryParser::TimeContext *ctx) {
    QNode *node = qNode(QNodeStringValue);
    // TODO memory leak
    node->value.s = strdup(ctx->getText().c_str());
    stack.push_back(node);
}


void QueryConcreteListener::exitQtrue(QueryParser::QtrueContext *ctx) {
    stack.push_back(qNode(QNodeTrueValue));
}

void QueryConcreteListener::exitQfalse(QueryParser::QfalseContext *ctx) {
    stack.push_back(qNode(QNodeFalseValue));
}

void QueryConcreteListener::exitRange(QueryParser::RangeContext *ctx) {
    QNode *rangeNode = qNode(QNodeRange);
    QNode *right = popAndRemove(stack);
    QNode *left = popAndRemove(stack);
    if (left->type == right->type) {
        left->next = right;
        rangeNode->value.children = left;
        stack.push_back(rangeNode);
    } else {
        isFailed = true;
        errorMessage = "different types in range:" + ctx->getText();
    }
}

bool isSameType(QNodeType t1, QNodeType t2) {
/* it should be this code rather than the one below but currently Orion doesn't consider true and false to be of the same type
 * if (t1 == t2)
        return true;
    return (((t1 == QNodeFalseValue) && (t2 == QNodeTrueValue)) || ((t1 == QNodeTrueValue) && (t2 == QNodeFalseValue)));*/
    return (t1 == t2);
}

void QueryConcreteListener::exitValuelist(QueryParser::ValuelistContext *ctx) {
    bool goOn = true;
    std::vector<QNode *> myStack;
    QNodeType currentType = QNodeVoid;
    while (!stack.empty() && goOn) {
        switch (stack.back()->type) {
            case QNodeStringValue:
            case QNodeTrueValue:
            case QNodeFalseValue:
            case QNodeFloatValue:
            case QNodeIntegerValue:
                if ((currentType == QNodeVoid) || isSameType(stack.back()->type, currentType)) {
                    currentType = stack.back()->type;
                    myStack.push_back(popAndRemove(stack));
                } else {
                    isFailed = true;
                    errorMessage = "different types in value list:" + ctx->getText();
                    goOn = false;
                }
                break;
            default:
                goOn = false;
                break;
        }
    }
    if (!isFailed) {
        auto comma = qNode(QNodeComma);
        auto current = &(comma->value.children);
        while (!myStack.empty()) {
            *current = popAndRemove(myStack);
            current = &((*current)->next);
        }
        auto c = comma->value.children;
        while (true) {
            c = c->next;
            if (c == nullptr) break;
        }
        stack.push_back(comma);
    }
}

void QueryConcreteListener::exitUri(QueryParser::UriContext *ctx) {
    QNode *node = qNode(QNodeStringValue);
    // TODO memory leak
    node->value.s = strdup(ctx->getText().c_str());
    stack.push_back(node);
}

void QueryConcreteListener::exitNumber(QueryParser::NumberContext *ctx) {
    QNode *node;
    double input = stod(ctx->getText());
    if (input == double(int(input))) {
        node = qNode(QNodeIntegerValue);
        node->value.i = input;
    } else {
        node = qNode(QNodeFloatValue);
        node->value.f = input;
    }
    stack.push_back(node);
}

void QueryConcreteListener::exitRegex(QueryParser::RegexContext *ctx) {
    string token = ctx->getText();
    if (token.length() > 4) {
        string expression = token.substr(3, token.size() - 4); // remove leading 'RE(' and trailing ')'
        QNode *value = qNode(QNodeRegexpValue);
        value->value.s = strdup(expression.c_str());
        stack.push_back(value);
    } else {
        isFailed = true;
        errorMessage = "encountered invalid regex:" + ctx->getText();
    }
}

void QueryConcreteListener::exitOpeningpar(QueryParser::OpeningparContext *ctx) {
    stack.push_back(
            qNode(QNodeOpen)); // this adds a marker for exitQueryTermAssoc to know when we reach the start of it
}

void QueryConcreteListener::exitDottedpath(QueryParser::DottedpathContext *ctx) {
}


void QueryConcreteListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                        size_t charPositionInLine, const string &msg, std::exception_ptr e) {
    isFailed = true;
    errorMessage = msg + " (character index " + to_string(charPositionInLine) + ")";
}

const std::string &QueryConcreteListener::getErrorMessage() const {
    return errorMessage;
}

bool QueryConcreteListener::hasFailed() const {
    return isFailed;
}
