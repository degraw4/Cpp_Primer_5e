#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
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

// 枚举，将一组整形常量组织在一起

int main(int argc, char** argv)
{
    // 定义了一个枚举类color，该类只能为RGB之一
    enum color {red = 1, blue = 2, green = 3};
    // 定义重复
    //enum light1 {red, blue, green};
    //enum light2 {red, yellow};

    color myColor = red;
    cout << myColor << endl;
    cout << typeid(myColor).name() << endl;
    // 某个枚举类，只可以用该类的成员赋值
    //myColor = 1;

    // 但是可以将枚举类赋值给整形变量
    int a = red;
    cout << a << endl;

    return 0;
}
