#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// 别名
// decltype

int main(int argc, char** argv)
{
    // arrT是int[10]的别名
    typedef int arrT[10];

    typedef double wages;
    wages a = 0, b = 0;

    using alias = double;
    alias c = 0, d = 0;

    // ptr 即为 double *
    typedef double * ptr;
    ptr p = &a;

    decltype(a) test = 0;
    // 对指针解引用的decltype结果为引用
    decltype(*p) p1 = a;
    // decltype(())为引用
    decltype((a)) c = a;

    return 0;
}
