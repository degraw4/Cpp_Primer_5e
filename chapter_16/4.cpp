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
#include <type_traits>

using namespace std;

int main(int argc, char** argv)
{
    // 对指针解引用，得到引用类型
    vector<int> vec;
    int b = 0;
    decltype(*vec.begin()) a = b;
    int* p;
    decltype(*p) c = b;

    // remove_ref
    // typename作用是让编译器知道::后面的type在这里是表示类型名字
    typename remove_reference<decltype(*p)>::type i = 0;

    return 0;
}
