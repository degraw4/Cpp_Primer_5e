#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// vector

int main(int argc, char** argv)
{
    // 值初始化，圆括号
    vector<int> v1(10, 1);
    vector<int>::size_type a = v1.size();
    // 二维值初始化
    vector<vector<int>> v2(10, vector<int>(10,0)); 
    // 列表初始化，方括号
    vector<int> v3{1,2,3,4,5};
    // 值初始化若无初始值，则int默认初始化为0，string为空字符串
    vector<int> v4(10);
    vector<string> v5(10);
    // 列表初始化格式不匹配，编译器自动转为值初始化
    vector<string> v6{10, "hi"};
    for(auto s : v6){
        cout << s << endl;
    }
    

    return 0;
}
