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

// catch的形参的静态类型决定了该形参的成员
// 基类形参传入了派生类，则无法调用派生类成员，因为被切掉了
// 最好将该形参声明为基类的引用，传入派生类时依旧可以动态绑定

class Base{
public:
    int a;
    virtual void test(){
        cout << "Base\n";
    }
};

class Derive: public Base {
public:
    int b;
    void test() override{
        cout << "Derive\n";
    }
};

int main(int argc, char** argv)
{
    try{
        throw Derive();
    }catch(Base& b){
        //int a = b.b;
        b.test();
    }
    return 0;
}
