#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <typeinfo>

using namespace std;

// lower_bound, upper_bound

int main(int argc, char** argv)
{
    vector<int> vec{1,2,3,4,4,5,6};
    cout << *lower_bound(vec.begin(), vec.end(), 4) << endl;
    cout << *upper_bound(vec.begin(), vec.end(), 4) << endl;
    return 0;
}
