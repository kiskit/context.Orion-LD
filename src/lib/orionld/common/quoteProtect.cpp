//
// Created by unby7436 on 10/11/22.
//
#include <string>
#include <boost/algorithm/string/replace.hpp>

std::string &quoteProtect(std::string &s) {
    boost::replace_all(s, "\"", "\\\"");
    return s;
}