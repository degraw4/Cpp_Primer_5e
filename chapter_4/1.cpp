#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 运算符

int main(int argc, char** argv)
{
    // 赋值运算符，返回左侧的对象，且为左值
    // 满足右结合律
    int v1, v2;
    v1 = v2 = 0;

    // 后置递增优先级高于解引用
    vector<int> vec = {1,2,3,4};
    for(auto iter = vec.begin(); iter != vec.end(); ){
        cout << *iter++ << endl;
    }

    // sizeof对于string和vector，与元素个数或者长度无关，只与该类型本身有关
    cout << sizeof(vec) << endl;
    string s1 = "";
    cout << sizeof(s1) << endl;

    cout << sizeof(vector<int>) << endl;
    cout << sizeof(vector<double>) << endl;
    cout << sizeof(vector<char>) << endl;
    cout << sizeof(vector<string>) << endl;
    
    return 0;
}
