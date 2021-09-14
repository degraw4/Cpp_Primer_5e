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

// 虚继承

class Base1{
public:
    int a;
};

class Base2: virtual public Base1{
public:
    int b;
};

class Derive: public Base2, virtual public Base1{
public:
    int c;
};

int main(int argc, char** argv)
{
    Derive d;
    return 0;
}
