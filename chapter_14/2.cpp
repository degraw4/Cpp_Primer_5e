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
#include <functional>

using namespace std;

// 类型转换运算符
// 必须是成员函数，无返回类型和参数列表，通常是const成员
// 用户的类型转换可以和内置类型转换一起执行，即使二者都被编译器隐式转换
class Book{
public:
    int price;
    // 此构造函数起到了int向Book转换的作用
    Book(int i = 0): price(i) {};
    // 将Book转换为int
    operator int() const { return price; }
};

int main(int argc, char** argv)
{
    vector<int> vec{1,2,3,4,5};
    // 使用标准库类型可以定义非默认排序
    sort(vec.begin(), vec.end(), greater<int>());

    Book book(10);
    // 显示调用转换
    int a = book.operator int();
    cout << a << endl;
    // 隐式调用转换
    int b = int(book);
    cout << b << endl;
    return 0;
}
