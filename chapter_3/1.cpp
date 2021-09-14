#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>

using namespace std;

// string

int main(int argc, char** argv)
{
    string s1(10, 'a');
    string s2(s1);

    // string::size_type 无符号数值
    string::size_type a =s1.size();

    // getline(is, string) 读入一行，包括回车，但是不把回车保存到string中
    while(getline(cin, s1)){
        cout << s1 << endl;
    }

    string s3 = "hello world";
    for(auto &c : s3){
        c = toupper(c);
        c = tolower(c);
        isalnum(c);
        isdigit(c);
        isalpha(c);
        ispunct(c);
    }
    return 0;
}
