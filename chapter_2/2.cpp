#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// 引用
// 指针

int main(int argc, char** argv)
{
    int val = 1024;
    int &refval = val;

    int value = 10;
    int *p = &value;
    cout << *p << endl;
    cout << p << endl;
    *p = 20;

    int *p1 = nullptr;
    int *p2 = 0;

    int *&red = p1;

    return 0;
}
