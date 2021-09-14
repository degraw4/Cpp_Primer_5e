#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <memory>
#include <typeinfo>

using namespace std;

class strBlobPtr;

class strBlob{
public:
    friend class strBlobPtr;
    typedef vector<string>::size_type size_type;
    strBlob();
    strBlob(initializer_list<string> li);

    size_type size() const {return data->size(); }
    bool empty() const {return data->empty();}

    void push_back(const string& s);

    void pop_back();
    
    string& front();

    const string& front() const;

    string& back();

    const string& back() const;

    strBlobPtr begin();

    const strBlobPtr begin() const;

    strBlobPtr end();

    const strBlobPtr end() const;

private:
    shared_ptr<vector<string>> data;
    void check(int index, const string& msg) const;
};

class strBlobPtr{
public:
    strBlobPtr(): curr(0) {}
    // 带有const的构造函数
    strBlobPtr(const strBlob &b, size_t index = 0): ptr(b.data), curr(index) {}

    string& deref();

    const string& deref() const;

    strBlobPtr& incr();

private:
    weak_ptr<vector<string>> ptr;
    size_t curr;
    shared_ptr<vector<string>> check(size_t index, const string& msg) const;
};