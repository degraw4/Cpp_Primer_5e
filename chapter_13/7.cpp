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

// 函数可以定义移动版和拷贝版的
// 拷贝版参数为const T&, 移动版参数为T&&
// 一般不需要参数为const T&& 或者 T&
void Function(const int&);
void Function(int&&);

// 引用限定符，决定成员函数的this指针指向左值or右值
class Foo{
public:
    vector<int> data;
    // 该函数的this指向左值，即只能向一个左值赋值
    Foo& operator=(const Foo&) &;
    // 该函数的this指向右值，即只能向一个右值赋值
    Foo operator=(const Foo&) &&;
    // const和引用限定符可以同时使用，且const在前
    Foo& operator=(const Foo&) const &;
    // 一个成员函数有了引用限定符，则具有相同参数列表的所有版本都要有引用限定符
};

// 类F的成员函数sort_copy()返回排序后的副本
class F{
public:
    vector<int> data;
    F sort_copy() const &;
    F sort_copy() &&;
};

// 调用此函数的类对象为左值
// 因此不能原地排序，否则会改变自身
F F::sort_copy() const &{
    F tmp(*this);
    // return tmp.sort_copy(); // 错误，会无限调用自身
    sort(tmp.data.begin(), tmp.data.end());
    return tmp;
}

// 调用此函数的类对象为左值，因此可以原地排序并返回自身
F F::sort_copy() &&{
    sort(data.begin(), data.end());
    return *this;
}

int main(int argc, char** argv)
{
    
    return 0;
}
