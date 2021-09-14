#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>
#include <array>

using namespace std;

int main(int argc, char** argv)
{
    // vector初始化
    vector<int> v1(10,1);
    vector<int> v2(v1);
    vector<int> v3(v1.begin(), v1.end());
    vector<int> v4{1,2,3,4};
    vector<int> v5 = {1,2,3,4};
    vector<vector<int>> vv(10, vector<int>(10,1));

    // 交换元素
    v1.swap(v2);
    swap(v1, v2);

    //cout << v1.size() << endl;
    //cout << v1.max_size() << endl;

    // array
    array<int, 10> a1{1,2,3};
    array<int, 3> a2 = {1,2,3};
    a2 = {1,2,3};

    // 赋值
    v1.assign(v2.begin(), v2.end());
    v1.assign({1,2,3,4});
    v1.assign(10,1);


    // assign和swap
    // 除了string容器，swap前后的迭代器、指针和引用不变
    v1 = {1,2,3};
    v2 = {4,5,6};
    int& r1 = v1[0];
    int* p1 = &v1[0];
    v1 = v2;
    cout << *p1 << endl;
    cout << r1 << endl;

    v1 = {1,2,3};
    v2 = {4,5,6};
    int& r2 = v1[0];
    int* p2 = &v1[0];
    swap(v1, v2);
    cout << *p2 << endl;
    cout << r2 << endl;


    return 0;
}
