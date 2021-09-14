#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// iterator

int main(int argc, char** argv)
{
    string s1 = "hello world";
    auto it1 = s1.begin();
    // end指向最后一个元素的下一个
    auto it2 = s1.end();
    // begin == end 为空

    // 迭代器相当于指针，要对迭代器解引用
    for(auto it = s1.begin(); it != s1.end() && !isspace(*it); it++){
        *it = toupper(*it);
    }
    return 0;

    // const_iterator
    auto ct1 = s1.cbegin();
    string::const_iterator it2 = s1.cend();

    auto it = (s1.begin() - s1.end());
}
