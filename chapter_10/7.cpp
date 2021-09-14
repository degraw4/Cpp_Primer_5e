#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <typeinfo>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> vec{1,1,2,3,4,5,1,2,3,4,1,2,3};
    auto iter = remove(vec.begin(), vec.end(), 1);
    for(auto e: vec){
        cout << e ;
    }
    cout << endl;
    cout << *iter << endl;
    return 0;
}
