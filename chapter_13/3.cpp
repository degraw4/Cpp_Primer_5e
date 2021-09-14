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

// 行为像值的类
class Value{
private:
    int i;
    string *ps;
public:
    friend void swap(Value& a, Value& b);
    Value(const string& s = ""): ps(new string(s)), i(0) {}
    Value(const Value& v): ps(new string(*v.ps)), i(v.i) {}
    Value& operator=(const Value& v); 
    Value& operator=(Value v); 
    ~Value() { delete ps; }
};
// 删除旧值+拷贝新值
Value& Value::operator=(const Value& v){
    auto p = new string(*v.ps);
    delete ps;
    ps = p;
    i = v.i;
    return *this;
}

// copy and swap, 天然的异常安全
Value& Value::operator=(Value v){
    swap(*this, v);
    return *this;
}

void swap(Value& a, Value& b){
    using std::swap;
    swap(a.ps, b.ps);
    swap(a.i, b.i);
}

// 行为像指针的类
class Ptr{
private:
    string* ps;
    int i;
    int* count;
public:
    Ptr(const string& s = ""): ps(new string(s)), i(0), count(new int(1)) {}
    Ptr(const Ptr& p): ps(p.ps), i(p.i), count(p.count) { ++*count; }
    Ptr& operator=(const Ptr& p);
    ~Ptr();
};

Ptr::~Ptr(){
    if(--*count == 0){
        delete ps;
        delete count;
    }
}

Ptr& Ptr::operator=(const Ptr& p){
    ++*p.count;
    if(--*count == 0){
        delete ps;
        delete count;
    }
    ps = p.ps;
    i = p.i;
    count = p.count;
    return *this;
}

int main(int argc, char** argv)
{
    
    return 0;
}
