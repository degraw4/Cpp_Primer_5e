#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 对于含有const或者引用的类，必须列表初始化，或者定义时自带初始值

class constRef{
private:
    int i = 1;
    const int ci = 0;
    int& ri = i;
public:
    //constRef(int ii):i(ii),ci(ii),ri(ii){};
    //constRef() = default;
    constRef(){};
};

// 当构造函数提供了默认实参，其作用相当于默认构造函数，即可以不提供实参进行构造
class Book{
public:
    string name;
    Book(string s = "test"):name(s){};
};

int main(int argc, char** argv)
{
    Book book;
    cout << book.name << endl;
    return 0;
}
