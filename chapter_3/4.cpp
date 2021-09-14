#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

// 数组

int main(int argc, char** argv)
{
    int arr[10];
    // 从右向左，是大小为10的数组，数组元素为指针，int类型的指针
    int *ptrs[10];
    // 引用不是对象，不存在引用的数组
    //int &refs[10];

    // 有括号，先从内向外，再从左向右
    // arr1是个指针，指向大小为10的数组，该数组为int数组
    int (*arr1)[10];
    // arr2是个引用，引用大小为10的数组，该数组为int数组
    int (&arr2)[10] = arr;
    // arr3是个引用，引用大小为10的数组，该数组为int *数组
    int *(&arr3)[10] = ptrs;

    // begin & end
    int *beg = begin(arr);
    int *en = end(arr);
    return 0;
}
