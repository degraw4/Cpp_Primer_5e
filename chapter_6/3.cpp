#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 形参为指针，实参可以为指针或变量取地址
void pointer(int *ptr){
    *ptr = 0;
    ptr = 0;
}

int main(int argc, char** argv)
{
    int a = 10;
    int b = 11;
    int *p = &b;
    pointer(&a);
    pointer(p);
    cout << a << endl;
    cout << a << endl;
    return 0;
}
