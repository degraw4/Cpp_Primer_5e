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
    StrVec(const StrVec& s);
    StrVec& operator=(const StrVec& s);
    int size() const { return first - last; };
    int capicity() const { return cap - first; };
    void push_back(const string& s);
    string pop_back();
    string* begin() const { return first; }
    string* end() const { return last; }
    ~StrVec() { free(); };
};

void StrVec::check_capicity(){
    if(size() == capicity()){
        reallocate();
    }
}

void StrVec::reallocate(){
    int new_capicity = size()  ? 2 * size(): 1;
    int old_size = size();
    auto new_first = alloc.allocate(new_capicity);
    for(int i=0; i < size(); i++){
        alloc.construct(new_first + i, std::move(*first++));
    }
    free();
    first = new_first;
    last = first + old_size;
    cap = first + new_capicity;
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
