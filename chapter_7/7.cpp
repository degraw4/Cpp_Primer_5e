#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 类的静态成员

class Account{
public:
    // 类的静态成员在类内只是声明，要单独在类外进行初始化 or 定义
    static double rate;
    double money;
    // 对于成员函数，加上static关键字说明为静态成员函数，可以通过类名作用域调用，否则只能通过类对象调用
    double getRate(){ return rate; }
    static double getRateStatic(){ return rate; }
};

// 类的静态成员的定义，static关键字只出现在类内
// 要通过作用域表明该变量属于哪个类
double Account::rate = 0;

int main(int argc, char** argv)
{
    Account ac1;
    // 可以通过Account::来调用类的静态成员和静态成员函数，也可以通过类对象调用
    cout << Account::rate << endl;
    cout << Account::getRateStatic() << endl;
    // 普通成员和成员函数只能通过类对象调用
    cout << ac1.rate << endl;
    cout << ac1.getRate() << endl;
    return 0;
}
