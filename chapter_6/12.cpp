#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 函数指针

// 函数
bool compare(string s1, string s2){
    cout << "function.\n";
    return true;
};

int main(int argc, char** argv)
{
    // 函数指针，前面为指向的函数的返回类型，后面为函数的形参列表，二者构成了函数类型
    // ()必不可少，不然变成了返回bool *类型的函数
    bool (*pf) (string s1, string s2);
    // 指针赋值，可以省略取地址符&
    // 函数名后面不跟()，参考数组名不跟[]，指针名不跟*
    pf = compare;
    pf = &compare;
    // 调用函数，可以省略解引用符*
    bool b1 = pf("a", "b");
    bool b2 = (*pf)("a", "b");

    return 0;
}
