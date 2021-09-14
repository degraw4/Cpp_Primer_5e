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
#include <random>
#include <ctime>

using namespace std;

// 随机数

vector<unsigned> randVec1(){
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0,100);
    vector<unsigned> ret;
    for(int i = 0; i < 100; ++i){
        ret.push_back(u(e));
    }
    return ret;
}

vector<unsigned> randVec2(){
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(0,100);
    vector<unsigned> ret;
    for(int i = 0; i < 100; ++i){
        ret.push_back(u(e));
    }
    return ret;
}

int main(int argc, char** argv)
{
    // 生成0-1之间的随机浮点数
    uniform_real_distribution<double> d(0, 1);
    // 生成N(0,1)的正态分布
    normal_distribution<double> n(0, 1);
    // 返回bool，生成true的概率为50%
    bernoulli_distribution b1;
    // 返回bool，生成true的概率为80%
    bernoulli_distribution b2(0.8);
    return 0;
}
