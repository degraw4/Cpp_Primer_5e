#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 返回类型为引用
int &ref_function(int &a){
    return a;
}

// 返回类型为指针
int *ptr_function(int &a){
    return &a;
}


int main(int argc, char** argv)
{
    int a = 0;
    // 此时auto类型为int，而不是int &
    // 因为int和int &可以类型转换？
    auto b_1 = ref_function(a);
    b_1 = 1;
    cout << a << endl;
    auto &b_2 = ref_function(a);
    b_2 = 1;
    cout << a << endl;

    // 返回指针，则不存在int和int *类型的转换
    // auto ptr = ptr_function(b)非法
    int b = 0;
    auto *ptr = ptr_function(b);
    *ptr = 1;
    cout << b << endl;

    return 0;
}
