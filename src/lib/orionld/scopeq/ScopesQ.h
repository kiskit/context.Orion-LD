#ifndef inputscope_h_included
#define inputscope_h_included

#include <string>
#include <vector>
#include <sstream>
#include <bson.h>

using namespace std;

class ScopeQ {
private:
    vector<string> levels;
    bool hasWildcard;
public:
    ScopeQ();

    ScopeQ(const string &level);

    void AddLevel(const string &level);

    bool toBson(bson_t *bsonP, char **titleP, char **detailsP) const;

    string String() const;

    // utils
    static ScopeQ stringToScope(const string &s);

};

class OrScopeQ {
private:
    vector<ScopeQ> andScopeqList;
public:

    OrScopeQ() {}

    ScopeQ &Last();

    void Append(const ScopeQ &_scope);

    //bool Matches(const vector<ScopeQ> &scopesToMatch) const;
    bool toBson(bson_t *bsonP, char **titleP, char **detailsP) const;

    string String() const;
};

class ScopesQ {
private:

    vector<OrScopeQ> orScopeqList;
public:

    ScopesQ();

    void Append(const OrScopeQ &_orScope);

    string String() const;

    bool toBson(bson_t *bsonP, char **titleP, char **detailsP) const;
};

#endif