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

// 函数模板
// 参数用const引用，尽量只用<，不用>
// 函数模板的定义以及类模板的成员函数的定义要在头文件中

// 模板定义和后面的函数定义是一起的
// 模板参数：
// 类型参数，typename或者class
// 非类型参数：用特定的类型名
template<typename T>
int compare(const T& a, const T& b){
    if(a < b)   return 1;
    if(b < a)   return -1;
    return 0;
}

template<typename T>
T* test(const T& a, const T& b){
    T* tmp = &a;
    return tmp;
}

// 非类型参数代表一个值，只能为整形或指针或引用，必须用常量表达式来实例化
// 比较两个字符数组长度，传参为数组引用，且包括长度
// 补充，数组作为形参，以指针形式传入时，可以用int*, int[], int[10], 此时10不起作用
//       用引用形式传入时，如int(&)[10]，此时只能作用于大小为10的数组
template<typename T, int M, int N, double* A, string& B>
int cmp(const char (&p)[M], const char (&q)[N]){
    return strcmp(p, q);
}

int main(int argc, char** argv)
{

    return 0;
}
