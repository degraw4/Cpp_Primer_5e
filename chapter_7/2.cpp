#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 构造函数

class Book{
    string name = "";
    double price = 0;
    // = default表示默认构造函数，不需要加{}
    // 类一定要定义默认构造函数
    Book() = default;
    // 构造函数的初始值列表，():,{}
    Book(const string& s, double p): name(s), price(p) {};
};

int main(int argc, char** argv)
{
    
    return 0;
}
