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

// 拷贝构造函数, 拷贝赋值运算符, 析构函数

using namespace std;

class Book{
public:
    Book() = default;
    Book(string s): name(s) {}

    // 拷贝构造函数，第一个参数为自身的引用，多为const类型，额外参数都有默认值
    // 一般不是explicit的
    Book(const Book& book): name(book.name) {}

    // 拷贝赋值运算符，为运算符重载，本质上是个成员函数
    // 运算符左侧对象为this，右侧对象为参数列表
    // =通常返回左侧运算对象的引用
    Book& operator=(const Book& book){
        name = book.name;
        return *this;
    }

    // 析构函数，无返回类型和参数列表
    // 析构函数自身不直接销毁成员，而是在函数体之后隐含的析构阶段销毁的
    ~Book(){}
private:
    string name;
};

int main(int argc, char** argv)
{
    
    return 0;
}
