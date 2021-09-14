#ifndef __TEXT__
#define __TEXT__
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

using namespace std;

class QueryResult;

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

# endif