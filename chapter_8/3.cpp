#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 分割未知长度字符串
// 先将line转化成sstream流，然后将sstream >> 输出到word中
void split(){
    string line, word;
    getline(cin, line);
    stringstream strm(line);
    while(strm >> word){
        cout << word << endl;
    }
}

// 将多个string保存到sstream中，最后一起输出
// 先strm << string，再输出strm.str()
void combine(){
    string s1("aaa"), s2("bbb"), s3("ccc");
    stringstream out;
    out << s1 << " ";
    out << s2 << " ";
    out << s3 << " ";
    cout << out.str() << endl;
}

int main(int argc, char** argv)
{
    string s("This is a test.");
    stringstream strm1; // 默认绑定了空字符串
    // 绑定sstream和string
    stringstream strm2(s);
    strm1.str(s);
    // 返回sstream绑定的string
    string out = strm2.str();
    cout << out << endl;
    //split();
    combine();
    return 0;
}
