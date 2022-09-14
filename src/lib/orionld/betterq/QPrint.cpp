//#include<qNode.h>
#include "QPrint.h"
//
// Created by unby7436 on 03/11/22.
//
using namespace std;
std::string nodeToSeparator(QNode *node) {
    switch (node->type) {
        case QNodeAnd:
            return ("and");
        case QNodeOr:
            return ("or");
        case QNodeEQ:
            return ("==");
        case QNodeNE:
            return ("!=");
        case QNodeGE:
            return (">=");
        case QNodeGT:
            return (">");
        case QNodeLE:
            return ("<=");
        case QNodeLT:
            return ("<");
        case QNodeMatch:
            return ("~=");
        case QNodeNoMatch:
            return ("!~=");
        default:
            return "";
    }
}

std::string val2str(QNode *n) {
    char tab[1024];
    QNodeType t = n->type;
    QNodeValue v = n->value;
    switch (t) {
        case QNodeComma:
            tab[0] = 0;
            n = n->value.children;
            for (int i = 0; n != nullptr; ++i, n = n->next) {
                sprintf(tab, "%s%s%s", tab, ((i != 0)?"," :"Value list("), val2str(n).c_str());
            }
            break;
        case QNodeRange:
            sprintf(tab, "Range(%s .. %s)", val2str(v.children).c_str(), val2str(v.children->next).c_str());
            break;
        case QNodeFloatValue:               // E.g.: '0.123'
            sprintf(tab, "%f", v.f);
            break;
        case QNodeIntegerValue:             // E.g.: '512'
            sprintf(tab, "%lld", v.i);
            break;
        case QNodeVariable:
        case QNodeRegexpValue:
        case QNodeStringValue:              // E.g.: "this is a string"
            return v.s;
            break;
        case QNodeTrueValue:                // 'true'
            return "true";
            break;
        case QNodeFalseValue:               // 'false'
            return "false";
        default:
            return "unknown value";
    }
    return tab;
}

std::string qPrint(QNode *node) {
    auto current = node->value.children;
    std::string str = "";
    auto sep = nodeToSeparator(node);
    if (sep.length() > 0) {
        while (current != nullptr) {
            if (str.length() == 0) {
                str += "(" + qPrint(current);
            } else {
                str += " " + sep + " " + qPrint(current);
            }
            current = current->next;
        }
        if (node->value.children != nullptr) {
            str += ")";
        };
    } else {
        if ((node->type == QNodeExists)) {
            return qPrint(node->value.children);
        } else {
            str = val2str(node);
        }
    }
    return str;
}
