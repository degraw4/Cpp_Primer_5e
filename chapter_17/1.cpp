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
#include <tuple>
#include <bitset>

using namespace std;

int main(int argc, char** argv)
{
    bitset<16> a(0ULL);
    bitset<16> b(1ULL);
    cout << a.any() << endl;
    cout << b.any() << endl;
    
    return 0;
}
