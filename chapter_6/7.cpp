#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 返回指向数组的指针的函数
// function(int a, int b)是个整体，函数名+形参列表共同表示函数本身
// (*function(int a, int b))说明该函数返回的是个指针
// int (*function(int a, int b))[]说明指针指向数组，数组为int类型
int (*function(int a, int b))[];

// 不加括号说明返回一个数组，数组元素为int*
// 但是C++不允许函数返回数组或者函数
// int *function_1(int a, int b)[];

// 尾置返回类型
// 表明函数的返回类型为int (*)[]，即指向数组的指针
auto function_2(int a) -> int (*)[];

// decltype定义返回数组的指针
int arr[] = {1,2,3,4,5};
decltype(arr) *function_3(int a);
// 定义变量，一般从右往左读，有括号先看括号里面的，例如int (*)[]
// []较为特殊，一般存在于变量名字的右边，但是在上面的decltype()中是个例外


int main(int argc, char** argv)
{
    // arrT是int[10]的别名，p是int*的别名
    typedef int arrT[10], *p;
    return 0;
}
