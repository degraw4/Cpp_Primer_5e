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

// RTTI

// 比较两个类的引用是否相等
class Base{
public:
    friend bool operator==(const Base& b1, const Base& b2);
    virtual bool equal(const Base& b) const{
        return a == b.a;
    }
private:
    int a;
};

class Derive: public Base{
public:
    bool equal(const Base& base) const override{
        auto p = dynamic_cast<const Derive&>(base);
        return b == p.b;
    }
private:
    int b;
};

bool operator==(const Base& b1, const Base& b2){
    return typeid(b1) == typeid(b2) && b1.equal(b2);
}

int main(int argc, char** argv)
{
    
}
