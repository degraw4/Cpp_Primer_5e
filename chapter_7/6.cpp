#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 转换构造函数
// 当类存在一个实参的构造函数时，编译器会自动将该实参的类型隐式转换为类类型

class Book{
public:
    string name;
    Book(string s = "test"):name(s){};
    void function(Book book){};
};

int main(int argc, char** argv)
{
    Book book;
    string s = "AYS-0001";
    // string会被隐式转为Book类
    book.function(s);
    // 编译器只自动进行一次类型转换，即不能由const char[]变为string，再变为Book
    //book.function("AYS-0001");
    // 可以用构造函数显式的将"AYS-0001"转为Book类
    book.function(string("AYS-0001"));
    book.function(Book("AYS-0001"));

    Book b1(s);// 直接初始化
    Book b2 = s;// 拷贝初始化
    // 拷贝初始化实际执行了隐式类型转换，即将string转换为Book，因此explicit关键字可以限制隐式类型转换来限制拷贝初始化
    return 0;
}
