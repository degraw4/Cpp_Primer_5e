#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <iterator>
#include <typeinfo>

using namespace std;

// pair

// 返回pair的函数可以直接列表返回，或者make_pair
pair<int, string> function(int index){
    if(index){
        return {1, "test"};
    }
    else{
        return make_pair(2, "test");
    }
}

int main(int argc, char** argv)
{
    pair<int, int> p1(1, 1), p2(1, 2), p3(0, 1);
    cout << (p1 < p2) << endl;
    cout << (p1 < p3) << endl;
    p1.first = 1;
    p1.second = 2;

    // map下标访问，若无该关键字，则初始化创建
    map<int, int> myMap;
    cout << myMap[1] << endl;
    myMap.erase(1);
    if(myMap.find(1) == myMap.end())
        cout <<"not found" << endl;
    cout << myMap.size()<< endl;
    return 0;
}
