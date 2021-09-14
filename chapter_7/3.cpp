#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 访问说明符, friend

// 构造函数，部分成员函数声明为public
// 数据成员，其余函数声明为private
// class默认private，struct默认public

class test{};

class Book{
    // 友元要在类内声明，可以让其余类或者函数访问类内的私有成员
    friend string outGetName(Book book);
    friend class test;
public:
    mutable int ctr = 0;
    Book() = default;
    Book(string s):name(s){};
    string getName(){ return  name;}
    void test();
    // const成员函数可以修改mutable成员
    void some_str() const{
        ctr++;
    }
private:
    string name = "";
    void changeName(string s){ name = s; }
};

// 在类外定义inline函数
inline
void Book::test(){};

// 友元也需要在类外声明
string outGetName(Book book){
    return book.name;
}

int main(int argc, char** argv)
{
    Book book("The Hound of the Baskervilles");
    //book.changeName("aa");
    cout << book.getName() << endl;
    cout << outGetName(book) << endl;
    return 0;
}
