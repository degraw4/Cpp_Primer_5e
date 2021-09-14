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
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered s){
    cout << s.mysn << endl;
}

int main(int argc, char** argv)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
