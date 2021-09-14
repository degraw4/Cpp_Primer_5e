#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <typeinfo>

// 流迭代器

using namespace std;

int main(int argc, char** argv)
{
    // 读取cin中的int，遇到不是int的就变为eof
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    while(in_iter != eof){
        // 先后置++，再解引用
        cout << *in_iter++ << endl;
    }

    // 可以使用流迭代器来构造容器
    istream_iterator<int> in_it(cin);
    vector<int> vec(in_it, eof);

    // ostream
    vector<int> v1{1,2,3,4,5};
    ostream_iterator<int> out_iter(cout, " ");
    // copy输出
    copy(v1.cbegin(), v1.cend(), out_iter);
    cout << endl;
    // 遍历输出
    for(auto a: vec){
        out_iter = a;
        // 等价于*out_iter++ = a;
    }
    return 0;
}
