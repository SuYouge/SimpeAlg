#include <iostream>
#include <stdio.h>
using namespace std;

// 函数指针的typedef
typedef int (*callback)(int, int);

/*
1、定义一个函数（普通函数即可）；
2、将此函数的地址注册给调用者；
3、特定的事件或条件发生时，调用者使用函数指针调用回调函数。
*/

// 回调函数

int ADD(callback p ,int a, int b){
    return (*p)(a,b);
}


// 普通函数
int add(int a, int b){
    return (a+b);
}

int main(){

    // cout<< " hello world ---"<<endl;
	printf("%d\n",ADD(add,1,2));
    return 0;
}