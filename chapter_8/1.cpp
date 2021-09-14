#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main(int argc, char** argv)
{
    cout << "This is a test." << endl; // \n
    cout << "This is a test." << ends; // \0
    cout << "This is a test." << flush; 

    cout << unitbuf; //设置每次输出都刷新
    cout << "This is a test.";
    cout << nounitbuf; //取消设置

    return 0;
}
