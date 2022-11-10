#include <iostream>
#include "ScopesQ.h"

using namespace std;
const char* scopeFieldName = "_id.scope";

ScopeQ::ScopeQ(const string &level) {
    levels.push_back(level);
}

ScopeQ::ScopeQ() : hasWildcard(false) {}

void ScopeQ::AddLevel(const string &level) {
    if (level == "#") {
        levels.push_back(".*");
        hasWildcard = true;
    } else if (level == "+") {
        levels.push_back("[^\\/]+"); // any character but /
        hasWildcard = true;
    } else {
        levels.push_back(level);
    }
}

/*bool ScopeQ::toBson(bson_t *bsonP, char **titleP, char **detailsP) const {
    if (hasWildcard) {
        bson_t matchBson;
        bson_init(&matchBson);
        bson_append_document_begin(bsonP, "scope", -1, &matchBson);
        bson_append_utf8(&matchBson, "$regex", 6, String().c_str(),
                         -1); // TODO watch out, string is destroyed at the end of this method. Is there a copy made in bson append?
        bson_append_array_end(bsonP, &matchBson);
    } else {
        bson_append_utf8(bsonP, "scope", -1, String().c_str(), -1);
    }
    return true;
}*/

bool ScopeQ::toBson(bson_t *bsonP, char **titleP, char **detailsP) const {
    // Must match arrays and single value fields
    // In the case of wildcards:
    //      {$or: [{scope: {$elemMatch: {$regex: "/Paris/.*"}}}, {scope: {$regex: "/Paris/.*"}}]}
    // Otherwise:
    //      {$or: [{scope: {$elemMatch: {$eq: "/Paris"}}}, {scope: {$eq: "/Paris"}}]}
    /*bson_copy_to(BCON_NEW(
                         "$or",
                         "[",
                         "{",
                         "scope",
                         "{",
                         "$elemMatch",
                         "{",
                         hasWildcard ? "$regex" : "$eq",
                         BCON_UTF8(strdup(String().c_str())),
                         "}",
                         "}",
                         "}",
                         "{",
                         "scope",
                         "{",
                         hasWildcard ? "$regex" : "$eq",
                         BCON_UTF8(strdup(String().c_str())),
                         "}",
                         "}",
                         "]"
                 ), bsonP);*/

    bson_t orArray = BSON_INITIALIZER;
    bson_append_array_begin(bsonP, "$or", -1, &orArray);
    bson_t firstOrElement = BSON_INITIALIZER;
    bson_append_document_begin(&orArray, "0", -1, &firstOrElement);
    bson_t firstScope = BSON_INITIALIZER;
    bson_append_document_begin(&firstOrElement, scopeFieldName, -1, &firstScope);
    bson_t firstElemMatch = BSON_INITIALIZER;
    bson_append_document_begin(&firstScope, "$elemMatch", -1, &firstElemMatch);
    if (hasWildcard) {
        BSON_APPEND_UTF8(&firstElemMatch, "$regex", String().c_str());
    } else {
        BSON_APPEND_UTF8(&firstElemMatch, "$eq", String().c_str());
    }
    bson_append_document_end(&firstScope, &firstElemMatch);
    bson_append_document_end(&firstOrElement, &firstScope);
    bson_append_document_end(&orArray, &firstOrElement);

    //cout << "In Scope:"<< bson_as_canonical_extended_json(bsonP, nullptr) << endl;

    bson_t secondOrElement = BSON_INITIALIZER;
    bson_append_document_begin(&orArray, "0", -1, &secondOrElement);

    bson_t secondScope = BSON_INITIALIZER;
    bson_append_document_begin(&secondOrElement, scopeFieldName, -1, &secondScope);
    if (hasWildcard) {
        BSON_APPEND_UTF8(&secondScope, "$regex", String().c_str());
    } else {
        BSON_APPEND_UTF8(&secondScope, "$eq", String().c_str());
    }
    bson_append_document_end(&secondOrElement, &secondScope);
    bson_append_document_end(&orArray, &secondOrElement);
    bson_append_array_end(bsonP, &orArray);


    cout << "In scope " << bson_as_canonical_extended_json(bsonP, nullptr) << endl;
    return true;
}

string ScopeQ::String() const {
    string s;
    for (auto &l: levels) {
        s += "/" + l;
    }
    return s;
}

void OrScopeQ::Append(const ScopeQ &_scope) {
    andScopeqList.push_back(_scope);
}

ScopeQ &OrScopeQ::Last() {
    return andScopeqList.back();
}

bool OrScopeQ::toBson(bson_t *bsonP, char **titleP, char **detailsP) const {
    if (andScopeqList.size() > 1) {
        bson_t andArrayBson = BSON_INITIALIZER;
        bson_append_array_begin(bsonP, "$and", 4, &andArrayBson);
        int i = 0;
        for (auto andScope: andScopeqList) {
            string s = std::to_string(i++);
            bson_t element = BSON_INITIALIZER;
            bson_append_document_begin(&andArrayBson, s.c_str(), -1, &element);
            if (!andScope.toBson(&element, titleP, detailsP)) {
                return false;
            }
            //bson_append_document_begin(&andArrayBson, s.c_str(), -1, element);
            cout << "element in AND:" << bson_as_canonical_extended_json(&element, nullptr) << endl;
            bson_append_document_end(&andArrayBson, &element);
        }
        cout << "whole AND clause1:" << bson_as_canonical_extended_json(&andArrayBson, nullptr) << endl;
        //cout << "whole AND clause2:" << bson_as_canonical_extended_json(bsonP, nullptr) << endl;
        bson_append_array_end(bsonP, &andArrayBson);
        //bson_destroy(&andArrayBson);
        cout << "after AND:" << bson_as_canonical_extended_json(bsonP, nullptr) << endl;
    } else {
        andScopeqList.back().toBson(bsonP, titleP, detailsP);
    }
    return true;
}

string OrScopeQ::String() const {
    string s;
    if (andScopeqList.size() > 1) {
        s += "(";
    }
    for (unsigned int i = 0; i < andScopeqList.size(); ++i) {
        if (i != 0) {
            s += " AND ";
        }
        s += andScopeqList[i].String();
    }
    if (andScopeqList.size() > 1) {
        s += ")";
    }
    return s;
}

ScopesQ::ScopesQ() = default;

void ScopesQ::Append(const OrScopeQ &_orScope) {
    orScopeqList.push_back(_orScope);
}

bool ScopesQ::toBson(bson_t *bsonP, char **titleP, char **detailsP) const {
    if (orScopeqList.size() > 1) {
        // { "$or": [ { }, { }, ... { } ] }
        bson_t orArrayBson;
        bson_init(&orArrayBson);
        bson_append_array_begin(bsonP, "$or", 3, &orArrayBson);
        for (auto orScope: orScopeqList) {
            bson_t orItemBson;
            bson_init(&orItemBson);
            bson_append_document_begin(&orArrayBson, "0", 1, &orItemBson);
            if (!orScope.toBson(&orItemBson, titleP, detailsP)) {
                return false;
            }
            bson_append_document_end(&orArrayBson, &orItemBson);
            cout << "Array:" << bson_as_canonical_extended_json(&orArrayBson, nullptr) << endl;
        }
        bson_append_array_end(bsonP, &orArrayBson);
        cout << "Top level :" << bson_as_canonical_extended_json(bsonP, nullptr) << endl;
    } else {
        if (!orScopeqList.back().toBson(bsonP, titleP, detailsP)) {
            return false;
        }
    }
    return true;
}

/*bool ScopesQ::Matches(const vector<ScopeQ> &scopesToMatch) const {
    return std::any_of(orScopeqList.begin(), orScopeqList.end(),
                       [scopesToMatch](const OrScopeQ &s) { return s.Matches(scopesToMatch); });
}*/

string ScopesQ::String() const {
    string s;
    for (unsigned int i = 0; i < orScopeqList.size(); ++i) {
        if (i != 0) {
            s += " OR ";
        }
        s += orScopeqList[i].String();
    }
    return s;
}

