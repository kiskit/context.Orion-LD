//
// Created by unby7436 on 22/11/22.
//

#include "QueryBuilderListener.h"
void QueryBuilderListener::exitQoperator(QueryParser::QoperatorContext * ctx) {

}

void QueryBuilderListener::exitPatternop(QueryParser::PatternopContext * ctx) {
    nodes.push_back(qNode(QNodeMatch));
}

void QueryBuilderListener::exitPatternnoop(QueryParser::PatternnoopContext * ctx) {
    nodes.push_back(qNode(QNodeNoMatch));
}

void QueryBuilderListener::exitGreatereq(QueryParser::GreatereqContext * ctx) {
    nodes.push_back(qNode(QNodeEQ));
}

void QueryBuilderListener::exitGreater(QueryParser::GreaterContext * ctx) {

}

void QueryBuilderListener::exitLess(QueryParser::LessContext * ctx) {
}

void QueryBuilderListener::exitLesseq(QueryParser::LesseqContext * ctx) {
}

void QueryBuilderListener::exitEqual(QueryParser::EqualContext * ctx) {
}

void QueryBuilderListener::exitUnequal(QueryParser::UnequalContext * ctx) {
}

void QueryBuilderListener::exitOthervalue(QueryParser::OthervalueContext * ctx) {
}

void QueryBuilderListener::exitQtrue(QueryParser::QtrueContext * ctx) {
}

void QueryBuilderListener::exitQfalse(QueryParser::QfalseContext * ctx) {
}

void QueryBuilderListener::exitDatetime(QueryParser::DatetimeContext * ctx)  {
    
    
}

void QueryBuilderListener::exitDate(QueryParser::DateContext * ctx)  {
    // TODO
}

void QueryBuilderListener::exitTime(QueryParser::TimeContext * ctx)  {
    // TODO
}

void QueryBuilderListener::exitNumber(QueryParser::NumberContext * ctx)  {
    nodes.push_back(qNode(QNodeFloatValue));
    // TODO
}

void QueryBuilderListener::exitOpeningpar(QueryParser::OpeningparContext * ctx)  {
    nodes.push_back(qNode(QNodeOpen));
}

void QueryBuilderListener::exitClosingpar(QueryParser::ClosingparContext * ctx)  {
    nodes.push_back(qNode(QNodeClose));
}