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
#include <stdexcept>
#include <cstdlib>

using namespace std;

// 重载new和delete
// 要定义在全局作用域或者类作用域内

// new的返回类型必须是void*，第一个参数必须为size_t，且无默认实参
// 可以用malloc申请内存，接受字节大小，返回void*的指针
void* operator new(size_t t){
    if(void* mem = malloc(t)){
        cout << "new\n";
        return mem;
    }
    throw bad_alloc();
}

// delete必须返回void，尽管标准库返回的是void*，第一个参数必须是void*
// delete必须是noexcept的
// 使用free函数来释放内存，其接受void*
void operator delete(void* mem) noexcept{
    cout << "delete\n";
    free(mem);
}

int main(int argc, char** argv)
{
    // 自定义版本
    int *p = new int(0);
    delete p;

    // 由于重载函数定义在了全局作用域中，所以::在全局作用域搜素，还是找到了自定义版本的
    // ::只会忽略类作用域中的
    p = ::new int(0);
    ::delete p;

    // 定位new，在指定内存上构造对象，无需分配内存
    // 传入的指针不需要指向动态内存
    int* new_p = new (p) int(0);
    delete new_p;

    return 0;
}
