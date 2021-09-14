#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> v = {1,2,3,4,5};
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.reserve(10);
    cout << v.capacity() << endl;
    v.shrink_to_fit();
    cout << v.capacity() << endl;

    vector<int> v2;
    int tmp = v2.capacity();
    cout << tmp << endl;
    for(int i = 0; i < 10000; i++){
        v2.push_back(i);
        if(tmp != v2.capacity()){
            tmp = v2.capacity();
            cout << tmp << endl;
        }
    }

    return 0;
}
