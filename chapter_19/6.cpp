#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
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

// union

int main(int argc, char** argv)
{
    // 定义Token类
    union Token {
        int i;
        char c;
        double d;
    };

    // 默认初始化Token类的第一个成员
    Token token1 = {1};
    Token token2;
    Token* tp = new Token;

    // 匿名union
    union{
        int ival;
        char cval;
        double dval;
    };

    ival = 1;
    cval = 'a';

    return 0;
}
