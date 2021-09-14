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

class Base{
public:
    Base() = default;
    Base(const Base& b): a(b.a) {}
    Base(Base&& b): a(b.a) {}
    Base& operator=(const Base& b) {
        a = b.a;
        return *this;
    }
    Base& operator=(Base&& b) {
        a = b.a;
        return *this;
    }
    ~Base() = default;
private:
    int a;
};

class Derive: public Base {
public:
    Derive() = default;
    // 派生类的基类成员默认使用基类的默认构造函数来初始化
    // 派生类要想使用移动或者拷贝构造函数，要在初始化列表中显示调用基类的对应函数
    Derive(const Derive& d): Base(d), b(d.b) {}
    // d虽然是右值引用类型，但其本身还是个左值，因此使用Base(std::move(d))
    Derive(Derive&& d): Base(std::move(d)), b(d.b) {}

    // 派生类的赋值运算符函数中也要显示调用基类的运算符函数
    Derive& operator=(const Derive& d){
        Base::operator=(d);
        b = d.b;
        return *this;
    }
    Derive& operator=(Derive&& d){
        Base::operator=(std::move(d));
        b = d.b;
        return *this;
    }

    // 与其余的拷贝控制成员不同，派生类的析构函数只负责自己的部分
    // 基类对象被自动销毁，不需要显示调用基类的析构函数
    // 且对象析构的顺序和构造的顺序相反，先析构派生类，再析构基类
    ~Derive() = default;
private:
    int b;
};

int main(int argc, char** argv)
{
    // 容器中通常存放基类的指针或智能指针，不能直接存放类对象
    vector<shared_ptr<Base>> vec;
    vec.push_back(make_shared<Base>());
    vec.push_back(make_shared<Derive>());

    // 直接存放类对象的话，虽然没有编译错误，但是派生类多余的对象会被切除
    vector<Base> bask;
    bask.push_back(Base());
    bask.push_back(Derive());
    return 0;
}
