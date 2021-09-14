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

// 移动构造函数，移动赋值运算符
// 移动迭代器

using namespace std;

class StrVec
{
private:
    static allocator<string> alloc;
    string* first;
    string* last;
    string* cap;
    void check_capicity();
    void reallocate();
    void free();
    pair<string*, string*> alloc_copy(const string* begin, const string* end);
public:
    StrVec(): first(nullptr), last(nullptr), cap(nullptr) {};
    StrVec(const initializer_list<string> &lst){
        auto tmp = alloc_copy(lst.begin(), lst.end());
        first = tmp.first;
        last = cap = tmp.second;
    }
    // 拷贝
    StrVec(const StrVec& s);
    StrVec& operator=(const StrVec& s);
    // 移动构造函数
    StrVec(StrVec&& s) noexcept;
    // 移动赋值运算符
    StrVec& operator=(StrVec&& s) noexcept;
    int size() const { return first - last; };
    int capicity() const { return cap - first; };
    void push_back(const string& s);
    string pop_back();
    string* begin() const { return first; }
    string* end() const { return last; }
    ~StrVec() { free(); };
};

// 移动构造函数
// noexcept紧跟形参列表，形参为非const的右值引用
// 要保证移后源依旧有效，可以析构，但是不保证数值是多少
StrVec::StrVec(StrVec&& s) noexcept: first(s.first), last(s.last), cap(s.cap) {
    s.first = s.last = s.cap = nullptr;
}

// 移动赋值运算符
// 先检查自赋值, this指针和对右值引用参数取地址得到的地址比较
StrVec& StrVec::operator=(StrVec&& s) noexcept{
    if(this != &s){
        free();
        first = s.first;
        last = s.last;
        cap = s.cap;
        s.first = s.last = s.cap = nullptr;
    }
    return *this;
}

void StrVec::check_capicity(){
    if(size() == capicity()){
        reallocate();
    }
}

// 移动版本的函数
// 使用移动迭代器和uninitialized_copy来保证“拷贝”元素的时候调用的是移动构造函数
void StrVec::reallocate(){
    int new_capicity = size()  ? 2 * size(): 1;
    auto new_first = alloc.allocate(new_capicity);
    // make_move_iterator()接受普通迭代器，返回移动迭代器
    // 对移动迭代器解引用得到右值引用
    auto new_last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), new_first);
    free();
    first = new_first;
    last = new_last;
    cap = last + new_capicity;
}

void StrVec::free(){
    if(first){
        // for_each返回的是*iter，以引用的形式捕获该返回值，然后&调用表示取地址
        // 最终得到的就是iter
        for_each(first, last, [](string &now) { alloc.destroy(&now); });
        alloc.deallocate(first, cap - first);
    }
}

pair<string*, string*> StrVec::alloc_copy(const string* begin, const string* end){
    auto new_first = alloc.allocate(end - begin);
    free();
    return {new_first, uninitialized_copy(begin, end, new_first)};
}

StrVec::StrVec(const StrVec& s){
    auto tmp = alloc_copy(s.begin(), s.end());
    free();
    first = tmp.first;
    last = cap = tmp.second;
}

StrVec& StrVec::operator=(const StrVec& s){
    auto tmp = alloc_copy(s.begin(), s.end());
    free();
    first = tmp.first;
    last = cap = tmp.second;
    return *this;
}

void StrVec::push_back(const string& s){
    check_capicity();
    alloc.construct(last++, s);
}

string StrVec::pop_back(){
    if(last == first){
        throw("Empty");
    }
    string s = *last;
    alloc.destroy(--last);
    return s;
}

int main(int argc, char** argv)
{
    
    return 0;
}