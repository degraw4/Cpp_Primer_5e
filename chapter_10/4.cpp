#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <typeinfo>
#include <functional>

using namespace std;
using namespace std::placeholders;

int function1(int a, int b, string s, double d){
    return a + b;
}


int main(int argc, char** argv)
{
    // bind() 函数适配器
    // 可以在调用时减少函数的参数，交换参数的顺序
    // 占位符的命名空间在 std::placeholders 下
    int tmp_i = 1;
    string tmp_s = "test";
    double tmp_d = 1.0;
    auto newFunction1 = bind(function1, std::placeholders::_1, _2, tmp_s, tmp_d);
    cout << newFunction1(1,2) << endl;
    // 用引用传递被bind绑定的参数
    // ref()
    auto newFunction1 = bind(function1, _1, _2, ref(tmp_s), tmp_d);
    return 0;
}
