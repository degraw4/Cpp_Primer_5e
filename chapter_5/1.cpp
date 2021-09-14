#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    /*
    switch:
    switch (a): a必须是整数或者枚举类型
    case必须是常量表达式，且与a类型匹配
    switch会执行匹配到的case及其后面所有的case
    */
    int a = 1.0;
    switch (a)
    {
    case 1:
        cout<<"here"<<endl;
        break;
    
    default:
        cout<<"there"<<endl;
        break;
    }

    return 0;
}
