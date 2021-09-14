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

using namespace std;

class numbered{
public:
    numbered(){
        mysn = unique++;
    }
    numbered(const numbered& n){
        mysn = unique++;
        cout << "copy\n";
    }
    numbered& operator=(numbered s){
        mysn = unique++;
        cout <<"assign\n";
    }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

// 函数传参和return的时候都调用了拷贝构造函数
// 即使return并没有被赋值，依旧调用拷贝构造函数
numbered f(numbered s){
    cout << s.mysn << endl;
    return s;
}

int main(int argc, char** argv)
{
    numbered a, b = a, c = b;
    cout << a.mysn << endl;
    cout << b.mysn << endl;
    cout << c.mysn << endl;
    f(a);
    f(b);
    auto d = f(c);
    return 0;
}
