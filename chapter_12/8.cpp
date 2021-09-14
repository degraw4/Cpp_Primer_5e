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

// weak_ptr

using namespace std;

int main(int argc, char** argv)
{
    // weak_ptr要绑定到shared_ptr上，
    shared_ptr<int> sp = make_shared<int>(42);
    weak_ptr<int> wp1(sp), wp2 = sp;
    weak_ptr<int> wp3 = wp2;
    
    cout << wp1.use_count() << endl;
    cout << wp1.expired() << endl;
    wp1.reset();
    cout << wp1.use_count() << endl;
    cout << wp1.expired() << endl;

    // wp不空，.lock()返回其指向的shared_ptr，否则返回空shared_ptr
    // 赋值运算符返回左侧变量，可以既赋值又用作if非空的判断
    // 不能直接用weak_ptr访问对象，要调用.lock()得到其shared_ptr来访问对象
    if(auto sp2 = wp2.lock()){
        cout << "wp2 is not empty.\n";
    }

    return 0;
}
