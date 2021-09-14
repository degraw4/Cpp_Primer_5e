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

// 右值引用

int main(int argc, char** argv)
{
    int a = 0;
    int& lr = a;    // 左值引用
    int&& rr1 = 42; // 右值引用
    int&& rr2 = a * 2;  // 右值引用
    const int& clr = 42;    
    const int&& crr = 42;   // const的左值或右值引用都可以绑定到右值上

    // std::move()返回左值的右值引用
    int&& r1 = std::move(a);
    
    return 0;
}
