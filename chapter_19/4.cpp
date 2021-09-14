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
#include <stdexcept>

using namespace std;

// 成员函数指针

class Base{
public:
    int test(int a, int b) const{
        return 1;
    };
};

int main(int argc, char** argv)
{
    // 定义一个指向Base::test函数类型的指针pf1
    int (Base::* pf1) (int, int) const;
    // 绑定该指针
    pf1 = &Base::test;
    int (Base::* pf2) (int, int) const = &Base::test;

    // 通过解引用来调用该函数指针
    Base base, *bp = &base;
    // 先解引用，再函数调用
    int a = (base.*pf1)(0, 0);
    int b = (bp->*pf1)(0, 0);

    //别名
    using action = int (Base::*) (int, int) const;

    return 0;
}
