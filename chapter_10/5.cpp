#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <typeinfo>

// 插入迭代器

using namespace std;

int main(int argc, char** argv)
{
    // 迭代器的类型要与容器能够支持的插入方式相同，例如front和back
    deque<int> vec;
    auto it1 = back_inserter(vec);
    auto it2 = front_inserter(vec);
    auto it3 = inserter(vec, vec.begin()+1);
    *it1 = 10;
    *it2 = 20;
    fill_n(it1, 5, -1);

    // 反向copy示例
    // 插入迭代器也属于迭代器，可以表示容器中的某一位置
    // 其与普通迭代器的区别为该迭代器可用于向容器中插入元素，且位置固定，时刻更新
    list<int> lst1{1,2,3,4};
    list<int> lst2;
    copy(lst1.cbegin(), lst1.cend(), front_inserter(lst2));

    return 0;
}
