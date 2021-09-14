#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> vec{1,2,3};
    for(auto iter: vec){
        cout << typeid(iter).name() << endl;
        cout << iter << endl;
    }
    return 0;
}
