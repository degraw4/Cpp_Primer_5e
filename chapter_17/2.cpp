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
#include <regex>

using namespace std;

// 正则表达式

int main(int argc, char** argv)
{
    string pattern = "[^c]ei";
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    string test("freind theif receipt receive");
    
    for(sregex_iterator it(test.begin(), test.end(), r), end_it;
        it != end_it; it++){
            cout << it->str() << endl;
        }

    // smatch result;
    // if(regex_search(test, result, r))
    //     cout << result.str() << endl;

    return 0;
}
