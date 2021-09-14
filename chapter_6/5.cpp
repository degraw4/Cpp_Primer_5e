#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 可变形参
// initializer_list

void function_1(const string s, initializer_list<int> lis){
    cout << s << endl;
}

void function_2(const string s, vector<int> lis){
    cout << s << endl;
}


int main(int argc, char** argv)
{
    function_1("test", {1,2,3});

    function_2("test", {1,2,3});

    // main函数传参，可选argv从1开始 
    cout << argc << endl;
    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
    }
    return 0;
}
