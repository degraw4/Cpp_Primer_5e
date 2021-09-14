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

// 使用类来管理union

class Token{
public:
    // 默认构造函数
    Token(): tok(INT), ival(0) {};
    // 拷贝
    Token(const Token& t): tok(t.tok) { copyUnion(t); };
    Token& operator=(const Token& t);
    // 移动
    Token(Token&& t): tok(std::move(t.tok)) { moveUnion(std::move(t)); }
    Token& operator=(Token&& t);
    // 析构函数
    ~Token() { if(tok == STR) sval.~string(); }
    Token& operator=(const string&);
    Token& operator=(char);
    Token& operator=(int);
    Token& operator=(double);
private:
    enum {INT, CHAR, STR, DBL} tok;
    union{
        int ival;
        char cval;
        string sval;
        double dval;
    };
    void copyUnion(const Token&);
    void moveUnion(Token&&);
};

Token& Token::operator=(const string& s){
    if(tok == STR){
        sval = s;
    }
    else{
        new (&sval) string(s);
        tok = STR;
    }
    return *this;
}

Token& Token::operator=(char c){
    if(tok == STR){
        sval.~string();
    }
    tok = CHAR;
    cval = c;
    return *this;
}

Token& Token::operator=(int i){
    if(tok == STR){
        sval.~string();
    }
    tok = INT;
    ival = i;
    return *this;
}

Token& Token::operator=(double d){
    if(tok == STR){
        sval.~string();
    }
    tok = DBL;
    dval = d;
    return *this;
}

// 在拷贝构造函数中调用copyUnion，说明此时union已经被默认初始化，即为ival
void Token::copyUnion(const Token& t){
    switch (t.tok){
    case INT:
        ival = t.ival;
        break;
    case CHAR:
        cval = t.cval;
        break;
    case DBL:
        dval = t.dval;
        break;
    case STR:
        // 要有string的构造函数
        new (&sval) string(t.sval);
        break;
    }
}

// 在移动构造函数中调用moveUnion，说明此时union已经被默认初始化，即为ival
void Token::moveUnion(Token&& t){
    switch (t.tok){
    case INT:
        ival = std::move(t.ival);
        break;
    case CHAR:
        cval = std::move(t.cval);
        break;
    case DBL:
        dval = std::move(t.dval);
        break;
    case STR:
        // 要有string的构造函数
        new (&sval) string(std::move(t.sval));
        break;
    }
}

// 根据双方是否为sval分情况
Token& Token::operator=(const Token& t){
    if(tok == STR && t.tok == STR){
        sval = t.sval;
    }
    if(tok == STR && t.tok != STR){
        sval.~string();
        copyUnion(t);
    }
    else{
        copyUnion(t);
    }
    tok = t.tok;
    return *this;
}

// 防止自赋值
Token& Token::operator=(Token&& t){
    if(this != &t){
        if(tok == STR) sval.~string();
        moveUnion(std::move(t));
        tok = std::move(t.tok);
    }
    return *this;
}

int main(int argc, char** argv)
{
    

    return 0;
}
