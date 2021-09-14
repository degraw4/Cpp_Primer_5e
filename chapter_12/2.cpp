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

using namespace std;

int main(int argc, char** argv)
{
    // make_shared<T> (args) 构造动态对象，并返回指向该对象的shared_ptr
    // 构造的动态对象可以为空，但是智能指针不空
    shared_ptr<int> sp1 = make_shared<int> (5);
    shared_ptr<string> sp2 = make_shared<string> ("test");
    auto sp3 = make_shared<int>();
    auto sp4 = make_shared<string>();

    // 拷贝构造
    shared_ptr<int> sp5(sp1);
    auto sp6(sp1);

    // 引用计数
    auto sp7 = make_shared<int>(1);
    cout << "sp7: " << sp7.use_count() << endl;
    auto sp8(sp7);
    cout << "sp7: " << sp7.use_count() << endl;
    cout << "sp8: " << sp8.use_count() << endl;
    sp7 = sp5;
    cout << "sp7: " << sp7.use_count() << endl;
    cout << "sp8: " << sp8.use_count() << endl;
    sp8 = sp5;
    cout << "sp7: " << sp7.use_count() << endl;
    cout << "sp8: " << sp8.use_count() << endl;
    return 0;
}
