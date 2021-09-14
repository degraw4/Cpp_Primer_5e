#define NDEBUG
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>
// 定义了宏NDEBUG，可以使assert()不工作
// 宏定义要在 #include <cassert> 之前，或者编译时加上 -D NDEBUG
#include <cassert>

using namespace std;

int main(int argc, char** argv)
{
    // assert() 为假终止程序，为真无事发生
    // assert最好为我们希望发生的条件
    int a = 1;
    assert(a == 0);
    cout << "here.\n";
    return 0;
}
