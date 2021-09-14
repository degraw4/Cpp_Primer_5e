#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// lambda表达式
// [capture list] (parameter list) -> return type {function body}

int main(int argc, char** argv)
{
    // 可以省略参数列表和返回类型
    auto f1 = []()->int{return 42;};
    auto f2 = [](){return 42;};
    auto f3 = []{return 42;};
    cout << f1() << endl;
    cout << f2() << endl;
    cout << f3() << endl;

    auto isShorter = [] (const string& s1, const string& s2) {return s1.size()<s2.size();};

    // for_each
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    for_each(vec.begin(), vec.end(),
            [] (int a) {cout << a << endl;});

    // 对于值传递的捕获参数，若想修改，需要加上mutable关键字
    int val = 10;
    auto f4 = [val] () mutable { return ++val; };
    auto f5 = [&val] () { return ++val; };

    return 0;
}
