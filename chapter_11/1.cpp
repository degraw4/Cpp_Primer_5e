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

// set, map对于自定义类的排序

using namespace std;

class Book{
public:
    string name;
    Book() = default;
    Book(string& s): name(s){}
    Book(const char* c): name(c){}
};

struct cmp{
    bool operator() (Book a, Book b) const{
    return a.name < b.name;
    }
};

bool compare(Book a, Book b) {
    return a.name.size() > b.name.size();
}

int main(int argc, char** argv)
{
    map<Book, int, cmp> myMap;
    map<Book, int, decltype(compare)*> myMap1(compare);
    set<Book, decltype(compare)*> mySet(compare);

    myMap1[Book("bb")] = 1;
    myMap1[Book("a")] = 1;
    for(auto a: myMap1){
        cout << a.first.name << endl;
    }

    return 0;
}
