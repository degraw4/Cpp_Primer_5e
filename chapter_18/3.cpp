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

// 将类的构造函数写为函数try语句块，可以处理初始化列表和函数体的异常
// 但是无法处理构造函数参数异常(调用参数不匹配?)，此时应该将整个构造函数放在try中

class T{
public:
    T(int b) try: a(b) {
        // 空函数体
    }catch(exception){}
    // noexcept说明该函数不会发生异常
    virtual void test() const noexcept final;
private:
    int a;
};

// noexcept最好出现在该函数所有的声明和定义中
void T::test() const noexcept{

}

int main(int argc, char** argv)
{
    
    return 0;
}
