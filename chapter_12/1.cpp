#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <memory>
#include <typeinfo>

// shared_ptr

using namespace std;

int main(int argc, char** argv)
{
    // 默认初始化的智能指针为空指针
    shared_ptr<string> p1;
    // 用if(p1)来判断p1是否为空指针
    if(p1){
        cout << "p1 is not a empty pointer.\n";
    }
    else{
        cout << "p1 is a empty pointer.\n";
    }
    //如果p1不是空指针，且其指向的string为空
    if(p1 && p1->empty()){
        *p1 = "this is a test";
        cout << *p1 << endl;
    }

    // .get()函数返回指向相同对象的普通指针
    auto a = p1.get();
    return 0;
}
