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

// shared_ptr和new一起用

using namespace std;

int main(int argc, char** argv)
{
    // new返回的内置指针不能隐式转换为智能指针，因此不能拷贝初始化，只能直接初始化
    shared_ptr<int> sp1(new int(10));
    //shared_ptr<int> sp2 = new int(10); // 错误代码
    shared_ptr<int> sp2(sp1);

    // 将内置指针p绑定到智能指针上后，不应该再用内置指针来访问该内存了，要用智能指针访问
    // 因为智能指针可能随时释放，此时p变为空悬指针
    int *p = new int(0);
    shared_ptr<int> sp3(p);

    // 不要用智能指针的.get()返回的内置指针初始化或赋值其他智能指针
    int *p2 = sp1.get();
    shared_ptr<int> sp4(p); // 危险

    // .reset()来释放智能指针或者指向新的对象
    sp1.reset();
    sp1.reset(new int(10));

    return 0;
}
