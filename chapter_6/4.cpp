#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 数组形参
// 传递 int * or int []

void red_array(int (&arr)[]){

}

void array_1(const int *){

}

void array_2(const int []){

}

void array_3(const int [5]){

}

void array_4(int *){

}

void array_5(int []){

}

void array_6(int [5]){

}

int main(int argc, char** argv)
{
    int arr[10]{1,2,3,4,5,6,7,8,9,0};
    int a = 0;
    array_1(arr);
    array_2(arr);
    array_3(arr);
    array_4(arr);
    array_5(arr);
    array_6(arr);

    
    array_1(&a);
    array_2(&a);
    array_3(&a);
    array_4(&a);
    array_5(&a);
    array_6(&a);
    return 0;
}
