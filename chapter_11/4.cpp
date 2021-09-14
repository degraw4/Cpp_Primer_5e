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
#include <unordered_set>

using namespace std;

int main(int argc, char** argv)
{
    unordered_multiset<int> se;
    cout << se.bucket_count() << endl;
    cout << se.max_bucket_count() << endl;
    cout << se.bucket_size(0) << endl;

    // 无序关联容器中，相同关键字的元素仍旧相邻
    se.insert(1);
    se.insert(2);
    se.insert(3);
    se.insert(1);
    se.insert(1);
    for(auto a: se)
        cout << a;
    return 0;
}
