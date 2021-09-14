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

// new动态数组

using namespace std;

int main(int argc, char** argv)
{
    // new数组，要有[]和数目，数目必须是整形，可以不是常量，可以是0
    // 返回指向数组首元素的指针，本质上并没有分配数组类型，而是分配了多个数组元素类型
    // 因此也无begin()和and()函数
    int *p1 = new int[10];
    string *p2 = new string[20];

    // 使用别名，new的时候可以不用[]
    typedef int arr[100];
    using arrT = int[100];
    int *p3 = new arr;
    int *p4 = new arrT;

    // new数组赋初值，空括号or列表初始化器
    int *p5 = new int[10]();
    int *p6 = new int[10]{0,1,2,3,4,5,6,7,8,9};
    string *p7 = new string[20]{"hello", "world", "test"};

    // delete动态数组，任何情况都要加括号[]
    delete [] p1;
    delete [] p2;

    // unique_ptr支持直接管理动态数组
    unique_ptr<int[]> up1(new int[10]());
    up1[0] = 1; // unique_ptr对动态数组定义了下标运算符
    up1[1] = 0;
    up1.release();  // release()会自动delete []数组

    // shared_ptr不支持直接管理动态数组，要自定义删除器
    // 且不支持下标运算，要返回内置指针才能操作动态数组，且智能指针不支持指针算术运算
    shared_ptr<int> sp1(new int[10](), [](int *p) { delete [] p; });

    return 0;
}
