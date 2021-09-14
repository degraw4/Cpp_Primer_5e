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

// 数据成员指针

class Base{
public:
    int a;
};

int main(int argc, char** argv)
{
    // 定义or赋值一个数据成员指针，只是将其指向了成员，而非某个实际的类对象
    // 在*之前和&之后都要加上类的限定符
    int Base::* p1 = &Base::a;
    auto p2 = &Base::a;

    // 通过解引用使用该指针时才将其绑定到具体对象上
    // 使用.*或->*结合具体的类对象来解引用数据成员指针，得到该类对象的数据成员的引用
    Base base, *bp = &base;
    int a = base.*p1;
    int b = bp->*p1;

    return 0;
}
