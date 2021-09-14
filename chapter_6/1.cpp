#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// static只初始化一次，生命周期为初始化到程序结束
// 无显式初始化，则执行值初始化为0，
int count(void){
    static int time;
    return ++time;
}

int main(int argc, char** argv)
{
    for(int i = 0; i < 10; i++){
        cout << count() << endl;
    }
    return 0;
}
