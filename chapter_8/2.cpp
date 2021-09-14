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
    fstream file1("txt");
    fstream file2;
    file2.open("txt", fstream::in | fstream::out | fstream::app);
    // 使用is_open()函数或者if(file)来检测是否打开文件成功
    cout << file1.is_open() << endl;
    if(file1)
        cout << "open" << endl; 
    file1.close();
    return 0;
}
