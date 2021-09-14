#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
    // 使用string初始化C风格字符串，必须是const *char类型
    string s = "hello world";
    const char *arr = s.c_str();
    return 0;

    // 数组初始化vector
    int array[] = {1,2,3,4,5};
    vector<int> vec(begin(array), end(array));
}
