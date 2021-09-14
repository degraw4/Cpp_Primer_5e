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

// 抽象类和纯虚函数

// B->D
// 用户代码：只有D是public继承，才可以D向B的类型转换
// D的成员和友元：任何继承都可以实现D向B的类型转换
// D的派生类的成员和友元：D是private继承则不可转换，其余皆可

class Abstract{
public:
    // 纯虚函数
    virtual void test() = 0;
private:
    int a;
};

class A {
public:
    int a;
};

class B: public A {
public:
    void f() {
        A* p = new B;
    }
};

class C: protected A {
public:
    void f() {
        A* p = new C;
    }
};

class D: private A {
public:
    void f() {
        A* p = new D;
    }
};

int main(int argc, char** argv)
{
    // 不能直接定义抽象类对象
    //Abstract a;

    // 派生类到基类的类型转换
    // 用户代码
    A* p;
    B b;
    C c;
    D d;
    p = new B;
    //p = new C;
    //p = new D;

    // 成员函数和友元代码
    b.f();
    c.f();
    d.f();
    return 0;
}
