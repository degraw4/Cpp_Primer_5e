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

// 智能指针指向普通对象而非动态对象，需要传递删除器

class Book{
    string name;
};

void BookDeleter(Book* book){
    // 一些删除和释放操作
    // 保证指向Book类的智能指针的释放
}

using namespace std;

int main(int argc, char** argv)
{
    Book book;
    // shared_ptr和unique_ptr格式不一样
    shared_ptr<Book> sp(&book, BookDeleter);
    unique_ptr<Book, decltype(BookDeleter)*> up(&book, BookDeleter);
    return 0;
}
