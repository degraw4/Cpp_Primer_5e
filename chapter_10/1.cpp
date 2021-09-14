#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <typeinfo>
#include <numeric>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> v1{1,2,3,4,5};
    vector<string> v2 = {"a", "b", "c"};
    int arr[] = {1,2,3,4,5};

    // find()
    auto result1 = find(v1.cbegin(), v1.cend(), 1);
    auto result2 = find(v2.cbegin(), v2.cend(), "s");
    int* result3 = find(begin(arr), end(arr), 1);

    // accumulate()
    // 字符串字面值类型为const char*，没有定义+运算符
    int sum = accumulate(v1.cbegin(), v1.cend(), 0);
    string sum2 = accumulate(v2.cbegin(), v2.cend(), string(""));

    // fill()
    fill(v1.begin(), v1.end(), 0);
    fill_n(v1.begin(), 2, 0);

    // back_inserter
    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 1;
    // 对于空容器不能直接用普通迭代器fill_n， 要用inserter迭代器
    fill_n(it, 10, 42);
    for(auto iter: vec){
        cout << iter << endl;
    }

    return 0;
}

