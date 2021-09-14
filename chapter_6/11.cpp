#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 自定义NDEBUG用于调试

void test(){
    #ifndef NDEBUG
    cerr << "ERROR: " << __FILE__ 
         << " : in function " << __func__ 
         << " at line: " << __LINE__ << endl
         << "Complied at: " << __TIME__ 
         << " on " << __DATE__ << endl
         << "NDEBUG TEST." << endl;
    #endif
}

int main(int argc, char** argv)
{
    test();
    return 0;
}
