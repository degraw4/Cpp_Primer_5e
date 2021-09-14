#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// 异常处理

void divide_1(int a, int b){
    // throw之后，程序寻找匹配的catch，找不到则终止该函数
    // throw语句的操作数可以是任意的表达式，catch也要与之对应
    if(b == 0){
        throw "Division by zero!";
    }
    // 不用担心b=0也会执行下一句，因为throw后找不到catch，此函数就终止了
    cout << a/b << endl;
}

void divide_2(int a, int b){
    if(b == 0){
        // throw标准异常类的话，跟的是类的构造函数
        throw exception();
    }
    cout << a/b << endl;
}

void divide_3(int a, int b){
    if(b == 0){
        throw runtime_error("Division by zero!");
    }
    cout << a/b << endl;
}

void divide_4(int a, int b){
    if(b == 0){
        throw b;
    }
    cout << a/b << endl;
}

int main(int argc, char** argv)
{
    try{
        divide_1(1,0);
    }catch(const char* err){
        cerr << err << endl;
    }
    
    try{
        divide_2(1,0);
    }catch(exception err){
        cerr << err.what() << endl;
    }

    try{
        divide_3(1,0);
    }catch(runtime_error err){
        cerr << err.what() << endl;
    }

    try{
        divide_4(1,0);
    }catch(int err){
        cerr << err << endl;
    }

    return 0;
}
