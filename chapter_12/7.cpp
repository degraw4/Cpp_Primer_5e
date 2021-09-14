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

// unique_ptr

using namespace std;

int main(int argc, char** argv)
{
    // unique_ptr没有类似make_shared函数，只能定义为空或者定义时绑定
    unique_ptr<int> up1;
    unique_ptr<int> up2(new int(10));

    // unique_ptr不支持拷贝和赋值，下面两行都错误
    // up1 = up2; 
    // unique_ptr<int> up(up1);
    // 例外情况：函数可以传参和返回unique_ptr

    // 释放up1，将其置空
    up1 = nullptr;
    
    // .release()返回指针并置空，多用于将指针从一个unique_ptr转到另一个
    unique_ptr<int> up3(up2.release());

    // .reset()置空ptr，.reset(p)将ptr指向p
    up3.reset();
    up3.reset(new int(10));
    unique_ptr<int> up4(new int(10));
    up3.reset(up4.release());

    // 自定义删除器格式和shared_ptr不同
    // unique_ptr <ObjType, decltype(function)*> up(new ObjType, function);
    return 0;
}
