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

// 类模板

// 类模板内如果还有模板，要用该类模板的类型参数T来替代
// 在类的自身作用域内，可以直接使用类名而不加实参
template<typename T> class Blob{
public:
    Blob() = default;
    Blob(initializer_list<T> lst): data(lst) {}
    ~Blob() = default;
    T& front();
    T& back();
    vector<T> data;
    static int times;
};

// 定义在类外的成员函数
// 要用模板开头，且类名中也要包含模板实参
template<typename T> T& Blob<T>::front(){
    T tmp;
    return tmp;
}

// 类模板的静态成员定义
template<typename T> int Blob<T>:: times = 0;

// 别名
template<typename T> using twin = pair<T, T>;
twin<int> a;

template<typename T> using test = Blob<T>;
test<int> b;

int main(int argc, char** argv)
{
    
    return 0;
}
