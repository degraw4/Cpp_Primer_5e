#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// const
// 顶层const：可用于任何对象，表示该对象本身是const
// 底层const：用于指针、引用等符合类型，表示该复合类型所指的底层变量为const变量

int main(int argc, char** argv)
{
    int a = 0;
    const int b = 0;
    // const在最前，根据从右向左读的原则，p1是个普通指针，只不过指向const对象
    // 是个指针，指向int，指向的int是const
    const int * p1 = &b;
    // p2指向const对象只是p2自己以为其指向const对象，但实际上可以不是const对象，且无法通过p2修改该对象的值
    const int * p2 = &a;
    // p3首先是const对象，其次才是指针，说明其指向不能改变
    int *const p3 = &a;
    // 双重const
    const int * const p4 = &b;
    return 0;
}
