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

// allocator类

using namespace std;

int main(int argc, char** argv)
{
    // .allocate()返回指向首地址的指针
    allocator<int> a;
    // 分配地址
    auto p = a.allocate(10);
    auto start = p;
    // 对每个内存位置构造元素
    for(int i = 0; i < 10; i++){
        a.construct(p++, i);
    }
    // 销毁每个位置的元素
    while(p != start){
        a.destroy(--p);
    }
    // 销毁内存
    a.deallocate(p, 10);

    return 0;
}
