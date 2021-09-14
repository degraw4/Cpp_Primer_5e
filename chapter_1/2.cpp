#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// 控制台文件重定向
/*
./2 <infile >outfile   输入输出重定向
echo test>file  将test写入file
cat>file  创建file，并且可以写入
cat file  输出file内容
*/

int main(int argc, char** argv)
{
   string input, output;
   cin >> input;
   output = input;
   cout << output << endl;
   return 0;
}
