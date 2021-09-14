#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <typeinfo>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <memory>
#include <new>
#include <utility>
#include <stdexcept>

using namespace std;

// 异常程序被捕获后，跳转到匹配的catch语句后执行

void test(){
    try{
        throw exception();
    }catch(runtime_error err){
        cout << err.what() << endl;
    }
    cout << 1 << endl;
}

int main(int argc, char** argv)
{
    try{
        test();
    }catch(exception e){
        cout << e.what() << endl;
    }
    cout << 2 << endl;
    
    return 0;
}
