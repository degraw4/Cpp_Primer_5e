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

// 自定义find()函数
template<typename U, typename T>
bool MyFind(const U& begin, const U& end, const T& target){
    // begin为const，不能修改
    auto start = begin;
    for(,;start != end; start++){
        if(*start == target){
            return true;
        }
    }
    return false;
}

// 自定义数组的begin和end函数
template<typename T, int M>
T* MyBegin(const T(&arr)[M]){
    return arr;
}

template<typename T, int M>
T* MyEnd(const T(&arr)[M]){
    return arr + M;
} 

int main(int argc, char** argv)
{
    
    return 0;
}
