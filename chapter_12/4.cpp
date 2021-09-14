#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <memory>
#include <typeinfo>
#include <new>

// new, delete
// 内置指针指向动态对象，即使该指针被销毁，若动态对象没有被显示释放，则该动态对象一直存在
// 上述情况极易导致内存泄漏

using namespace std;

int main(int argc, char** argv)
{
    int *p1 = new int;  // *p1值未定义
    int *p2 = new int();   // *p2为0
    int *p3 = new int(0);   // *p3为0
    string *p4 = new string;    //*p4为空字符串
    string *p5 = new string();  //*p5为空字符串
    vector<int> *p6 = new vector<int>{1,2,3,4,5};

    // 使用auto，p7为指向p3的指针
    auto p7 = new auto(p3);
    cout << p7 << endl;
    cout << *p7 << endl;
    cout << **p7 << endl;

    // new也可以指向常量，底层const
    const int* p8 = new const int(1024);

    // 定位new, 使用nothrow防止内存耗尽抛出bal_alloc
    int* p9 = new (nothrow) int(1024);

    // delete只能释放动态指针和空指针
    delete p1;
    delete p2;
    int* pn = nullptr;
    delete pn;
    delete p8;

    // delete后置为nullptr
    p8 = nullptr;

    return 0;
}
