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

// 多个对象共享数据：使用动态内存

using namespace std;

class strBlob{
public:
    typedef vector<string>::size_type size_type;
    strBlob();
    strBlob(initializer_list<string> li);
    size_type size() const {return data->size(); }
    bool empty() const {return data->empty();}
    void push_back(const string& s);
    void pop_back();
    // 常量成员可以调用const成员函数，但是无法调用非const的成员函数
    // 因此不改变类的函数都应该加上const关键字，一些函数还要进行const重载
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;
    
private:
    shared_ptr<vector<string>> data;
    void check(int index, const string& msg) const;
};

// 默认构造函数，令data指向一个空的vector
// 若加上=default，则说明该函数执行默认行为，即编译器的默认初始化，不会执行其他行为
strBlob::strBlob() { data = make_shared<vector<string>>(); }
strBlob::strBlob(initializer_list<string> li): data(make_shared<vector<string>>(li)) {}

void strBlob::push_back(const string& s){
    data->push_back(s);
}

void strBlob::pop_back(){
    check(0, "pop_back on empty strBlob");
    data->pop_back();
}

string& strBlob::front(){
    check(0, "front on empty strBlob");
    return data->front();
}

const string& strBlob::front() const{
    check(0, "front on empty strBlob");
    return data->front();
}

string& strBlob::back(){
    check(0, "back on empty strBlob");
    return data->back();
}

const string& strBlob::back() const{
    check(0, "back on empty strBlob");
    return data->back();
}

void strBlob::check(int index, const string& msg) const {
    if(index >= data->size()){
        throw out_of_range(msg);
    }
}

int main(int argc, char** argv)
{
    
    return 0;
}
