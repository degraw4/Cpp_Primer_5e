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

// 自定义Basket

class Base{
public:
    Base() = default;
    Base(const Base& b): a(b.a) {}
    Base(Base&& b): a(b.a) {}
    Base& operator=(const Base& b) {
        a = b.a;
        return *this;
    }
    Base& operator=(Base&& b) {
        a = b.a;
        return *this;
    }
    ~Base() = default;

    virtual Base* clone() const &{
        return new Base(*this);
    }

    virtual Base* clone() &&{
        return new Base(std::move(*this));
    }
private:
    int a;
};

class Derive: public Base {
public:
    Derive() = default;
    Derive(const Derive& d): Base(d), b(d.b) {}
    Derive(Derive&& d): Base(std::move(d)), b(d.b) {}
    Derive& operator=(const Derive& d){
        Base::operator=(d);
        b = d.b;
        return *this;
    }
    Derive& operator=(Derive&& d){
        Base::operator=(std::move(d));
        b = d.b;
        return *this;
    }
    ~Derive() = default;

    virtual Derive* clone() const &{
        return new Derive(*this);
    }

    virtual Derive* clone() &&{
        return new Derive(std::move(*this));
    }
private:
    int b;
};

class Basket{
public:
    void add(const Base& b){
        vec.push_back(shared_ptr<Base>(b.clone()));
    }
    void add(Base&& b){
        vec.push_back(shared_ptr<Base>(std::move(b).clone()));
    }
private:
    vector<shared_ptr<Base>> vec;
};


int main(int argc, char** argv)
{
    
    return 0;
}
