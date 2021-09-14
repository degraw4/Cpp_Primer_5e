#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// const_cast与重载函数

const string &shorterString(const string &s1, const string &s2){
    return s1.size() < s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2){
    auto & result = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(result);
}

int main(int argc, char** argv)
{
    // const_cast只能增加/去掉底层const
    const int a = 10;
    int* ptr = const_cast<int*>(&a);
    // const_cast转换后的修改是未定义行为
    *ptr = 0;
    cout << a << endl;
    cout << *ptr << endl;
    cout << &a << endl;
    cout << ptr << endl;
    return 0;
}
