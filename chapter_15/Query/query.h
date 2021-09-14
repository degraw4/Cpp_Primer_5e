#ifndef __QUERY__
#define __QUERY__
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <typeinfo>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <memory>
#include <new>
#include <utility>

using namespace std;

class QueryResult;
class TextQuery;
class Query;
class QueryBase;
class WordQuery;
class NotQuery;
class BinaryQuery;
class OrQuery;
class AndQuery;

ostream& print(ostream& os, const QueryResult& qr);

class TextQuery{
public:
    TextQuery(ifstream &in);
    QueryResult query(const string& s) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<int>>> times;
};

class QueryResult{
public:
    friend ostream& print(ostream& os, const QueryResult& qr);
    QueryResult(string s, shared_ptr<vector<string>> f, shared_ptr<set<int>> l):
        word(s), file(f), lines(l) {}
private:
    string word;
    shared_ptr<vector<string>> file;
    shared_ptr<set<int>> lines;
};

class QueryBase{
    friend class Query;
protected:
    ~QueryBase() = default;
private:
    virtual QueryResult eval(const TextQuery& text) const = 0;
    virtual string rep() const = 0;
};

class Query{
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(): p()
private:
    shared_ptr<QueryBase> p;
};

#endif