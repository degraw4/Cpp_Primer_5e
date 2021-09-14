#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 函数指针作为函数形参

bool compare(string s1, string s2){
    cout << "function.\n";
    return true;
};

bool (*pf) (string s1, string s2);

// 函数作为函数的形参，以下三个声明等价
void test(int a, bool (string s1, string s2));
void test(int a, bool compare(string s1, string s2));
void test(int a, bool (*pf)(string s1, string s2));

int main(int argc, char** argv)
{
    // 函数类型别名
    typedef bool F(string s1, string s2); // 形参列表类似数组[]后置
    typedef decltype(compare) F2;
    using F3 = bool (string s1, string s2);

    // 函数指针类型别名
    typedef bool (*PF)(string s1, string s2); 
    typedef decltype(compare) *PF2;
    using PF3 = bool (*)(string s1, string s2);

    // 函数返回类型为指向函数的指针
    PF function1(int, int*);
    //F function2(int, int*); // 错误，不允许函数返回类型为函数
    F *function3(int, int*);
    // function4是个函数，返回类型为指针，指针指向函数类型
    bool (*function4(int, int*)) (string s1, string s2); 
    auto function5(int, int*) -> bool (*)(string s1, string s2); // 尾置返回类型
    decltype(compare) *function(int, int*);

    return 0;
}
