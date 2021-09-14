#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// 进制
// 字符串字面值
// 初始化

int main(int argc, char** argv)
{
    int a = 024;
    int b = 0x24;    
    cout << a <<" " << b << endl;
    string sentense = "this is a test " 
        "about string?";
    cout << sentense << endl;

    int c = {0};
    int d {0};
    int e(0);

    c = {0};

    /*
    * error
    * int f, g = {1, 2};
    */
    return 0;
}
