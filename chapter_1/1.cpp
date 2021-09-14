#include <cstdio>
#include <iostream>
using namespace std;

// g++参数
// 终止输入

int main(){
    // ctrl+D to stop input
    int sum = 0, value = 0;
    while(cin >> value){
        sum += value;
    }
    cout << sum << endl;
    /*
    * this is a comments
    */
    return 0;
}