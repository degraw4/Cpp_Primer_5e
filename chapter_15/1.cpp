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

using namespace std;

//用户代码中，派生类到基类的转换只能在public继承的条件下

class Base{
public:
    int a;
private:
    int b;
protected:
    int c;
};

class Derive1: public Base {
    int d;
};

class Derive2: private Base {
    int d;
};


class Derive3: protected Base {
    int d;
};


int main(int argc, char** argv)
{
    Base *p, base;
    Derive1 d1;
    Derive2 d2;
    Derive3 d3;
    p = &base;
    p = &d1;
    //p = &d3;
    //p = &d3;
    return 0;
}
