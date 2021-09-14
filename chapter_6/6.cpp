#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 返回引用可以作为左值
int &ref_function(int &a){
    
    int *p1 = &a;
    cout << p1 << endl;
    return a;
}

// 函数可以返回花括号列表
vector<string> return_list_1(){
    return {"a", "b"};
}

vector<string> return_list_2(){
    return {};
}

int return_list_3(){
    return {1};
}

int return_list_4(){
    return {};
}

int main(int argc, char** argv)
{
    int a = 0;
    int *p0 = &a;
    cout << p0 << endl;
    ref_function(a) = 1;
    //cout << a << endl;

    vector<string> vec = return_list_1();
    cout << vec.size() << endl;
    vec = return_list_2();
    cout << vec.size() << endl;
    int b = return_list_3();
    cout << b << endl;
    b = return_list_4();
    cout << b << endl;
    return 0;
}
