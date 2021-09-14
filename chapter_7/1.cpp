#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// class
/*
一般将类定义在头文件中，类相关的非成员函数也声明在该头文件中
类的成员函数的定义可以在类的.cpp文件中
类相关的非成员函数定义在另一个.cpp文件中
*/

class Book{
    string name;
    double price = 0;
    // ()后的const说明是常量成员函数，隐式的让this指针可以指向常量的类类型
    // 默认inline
    double getPrice() const { return price; }
    string getName() const;
    Book& combine(Book& book);
};

// 成员函数定义在类外，则需要在函数名前加上类名的作用域，且其余保持与声明一样
string Book::getName() const{
    return name;
}

// 返回this指针的函数，返回类型为类的引用，return *this
Book& Book::combine(Book& book){
    price += book.price;
    return *this;
}

int main(int argc, char** argv)
{
    
    return 0;
}
