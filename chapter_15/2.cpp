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

// 动态绑定
// 动态绑定只在 指针或者引用调用虚函数时 才会发生

class Quote{
public:
    Quote() = default;
    Quote(const string& book, double sale_price)
        :bookNo(book), price(sale_price) {};
    virtual double get_price() const { return price; }
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price;
};

class Bulk: public Quote {
public:
    Bulk() = default;
    Bulk(const string& book, double price, double discount)
        : Quote(book, price), discount_price(discount) {}
    double get_price() const override { return discount_price; }
    // 虚函数一定要定义
    ~Bulk() override {};
private:
    double discount_price;
};

// 在此函数中，item为引用，其动态类型静态类型可能不一样
// 当引用类型item调用虚函数时，即item.get_price()，发生动态绑定
void GetPrice(ostream& os, const Quote& item){
    os << item.get_price() << endl;
}

int main(int argc, char** argv)
{
    Quote base("Base", 20);
    Bulk bulk("Bulk", 20, 10);
    // 普通对象调用虚函数get_price()，并不会发生动态绑定
    cout << base.get_price() << endl;
    // 动态对象调用才会发生
    GetPrice(cout, base);
    GetPrice(cout, bulk);

    return 0;
}
