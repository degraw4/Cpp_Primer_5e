#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>
#include <list>

using namespace std;

// 对于容器，插入删除可能导致迭代器、指针和引用失效
// 若未重新分配容器控件，指向容器本身的不会失效，但指向容器内元素的会失效

int main(int argc, char** argv)
{
    vector<int> v1;
    vector<int>* p1 = &v1;
    vector<int>& r1 = v1;

    for(int i=0; i<10; i++){
        v1.push_back(i);
    }
    int* p2 = &v1[1];
    int& r2 = v1[1];

    cout << (*p1)[1] << endl;
    cout << r1[1] << endl;
    cout << *p2 << endl;
    cout << r2 << endl;

    for(int i= 10; i<30; i++){
        v1.push_back(i);
    }

    cout << (*p1)[1] << endl;
    cout << r1[1] << endl;
    cout << *p2 << endl;
    cout << r2 << endl;

    // 使用insert的返回值在某一位置反复插入元素
    // 可以防止由于插入元素而造成的迭代器失效的问题，因为iter时刻在更新
    list<int> list1;
    auto iter = list1.begin();
    while(1){
        iter = list1.insert(iter, 1);
    }

    // emplace 直接构造元素放入容器
    // 函数的参数应该符合容器元素的构造函数的参数要求
    vector<string> vs1;
    vs1.emplace(vs1.begin(), "test");
    vs1.emplace_back("still test");

    return 0;
}
