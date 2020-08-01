#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;;

void Printer(int* val){
    cout<<"传入的值为："<<*val<<endl; 
}


int main(){

    /*如何获得void*中的值*/

    double d = 1.23; // 输出 1.23
    int i = 100;    // 未定义的结果
    void* p = &d;   
    void* q = &i;
    double *dp = static_cast<double*>(p);
    double *dq = static_cast<double*>(q);

    // int *dp = static_cast<int*>(p);
    // int *dq = static_cast<int*>(q);

    cout<<"存放于void*中的值为"<<*dp<<endl;
    cout<<"存放于void*中的值为"<<*dq<<endl;   

    /*如何使用 const_cast*/

    const int const_value = 10;
    const int* const_p = &const_value;
    int* modify = const_cast<int*>(const_p);
    *modify = 7;

    cout<<"const_value = "<<const_value<<endl; // const_value依然是10
    cout<<"*const_p = "<<*const_p<<endl;
    cout<<"*modify = "<<*modify<<endl; // 未定义行为，由编译器决定细节

    /*为何使用const_cast*/

    //原因1： 调用一个参数不是const的函数，但传入的参数是cosnt的，需要去除const限定以便函数能够接受这个实际参数

    Printer(const_cast<int* >(&const_value));

    //原因2： const作为函数重载标识符时，const对象想调用自身的非const方法

    //原因3： 非const变量被const指针指向，后续需要修改的时候只有通过指针去除const特性才能进行修改

    int notconst_value = 20;
    const int* const_p2 = &notconst_value;
    int* modify2 = const_cast<int*>(const_p2);
    *modify2 = 10 ;
    cout<<"notconst_value = "<<notconst_value<<endl; //已被修改
    cout<<"*const_p2 = "<<*const_p2<<endl;
    cout<<"*modify2 = "<<*modify2<<endl;

    vector<int>list = {1,-1,-1,-1,1,-1};
    transform(list.begin(),list.end(),list.begin(),
    [](int i){return i<0 ? -i : i;});
    for(auto iter = list.begin(); iter != list.end();iter++){
        cout<<*iter;}
    cout<<endl;

    return 0;
}