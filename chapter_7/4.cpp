#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// const成员函数返回*this

class Screen{
public:
    using ScreenIndex = int;
    Screen() = default;
    Screen& display(){ cout << "1" << endl;  return *this; };
    // 根据调用对象是否为const来重载函数
    // const成员函数表明this指向常量对象，因此返回类型为常量引用
    const Screen& display() const { cout << "2" << endl;  return *this; };
    ScreenIndex get(){};
};

// 返回类型为类内成员，则也需要加上类的作用域
// 成员函数的函数名前也要加上类的作用域
Screen::ScreenIndex Screen::get(){ return 0;}

int main(int argc, char** argv)
{
    Screen s1;
    const Screen s2;
    s1.display();
    s2.display();
    return 0;
}
