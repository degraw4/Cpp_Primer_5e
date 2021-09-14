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

// 输入输出运算符重载
// 必须定义为非成员函数

class Book{
public:
    string name;
    friend ostream& operator<<(ostream& os, const Book& book);
    friend istream& operator>>(istream& is, Book& book);
};

// 输出重载，参考 cout << data
// 第一个参数为os引用，第二个参数为输出内容的常量引用，返回os引用
ostream& operator<<(ostream& os, const Book& book){
    os << book.name;
    return os;
}

// 输入重载，参考 cin >> data
// 第一个参数为is引用，第二个参数为要输入对象的引用，返回is引用
istream& operator>>(istream& is, Book& book){
    is >> book.name;
    // 输出不需要错误检测，输入要检查，如果出错，要把对象置空
    if(!is){
        book = Book();
    }
    return is;
}

int main(int argc, char** argv)
{
    
    return 0;
}
