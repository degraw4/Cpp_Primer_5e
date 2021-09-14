#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// 自定义谓词
bool compare(const string& s1, const string& s2){
    return s1 < s2;
}

bool shorter(const string& s1, const string& s2){
    return s1.size() < s2.size();
}

int main(int argc, char** argv)
{
    vector<string> names = {"alan", "bob", "canthy", "daviad", "john", "bob", "alan"};
    sort(names.begin(), names.end());
    // unique()只把相邻的重复元素放在容器尾部，并且返回第一个重复元素的迭代器
    auto end_unique = unique(names.begin(), names.end());
    // 要想去重，unique()后还要erase()
    names.erase(end_unique, names.end());
    
    // 自定义sort，谓词只有名字，没有括号
    sort(names.begin(), names.end(), compare);
    // stable_sort，不改变在此排序规则下相等的元素的原有顺序
    stable_sort(names.begin(), names.end(), shorter);
    return 0;
}
