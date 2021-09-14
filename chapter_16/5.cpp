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

// 可变模板参数

// sizeof...返回的是包中有多少个元素，而不是多少种
template<typename T, typename... Args> 
void Foo(const T& t, const Args&... rest){
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

// 可变参数函数通常递归调用
template<typename T>
void print(const T& t){
    cout << t << endl;;
}

template<typename T, typename... Args>
void print(const T& t, const Args&... rest){
    cout << t << " ";
    // 向函数传递参数包实参
    print(rest...);

    // function(rest)...;
    // 对rest包中的每个元素都独立的调用funct函数
}

// 可变模板参数+转发
template<class... Args>
void Fun(Args&&... args){
    print(std::forward<Args>(args)...);
}

int main(int argc, char** argv)
{
    int i = 0;
    double d = 1.0;
    string s = "hi";
    //Foo(i);
    //Foo(i, d);
    //Foo(i, d, s);
    Foo(i, d, d, s);
    //Foo(i, d, s, 42);

    print(1,2,3,4,5,6,7,8,9,10);

    return 0;
}
