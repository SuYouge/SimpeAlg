/*
 * @Author: Yogurt Suee
 * @Date: 2020-02-19 18:03:22
 * @LastEditors: Yogurt Suee
 * @LastEditTime: 2020-02-19 18:37:10
 * @Description: 处理函数已经结束，线程依旧访问局部变量的情况
 */

#include <thread>
#include <iostream>

void do_something(int i){
    std::cout<<i<<"\n"<<std::endl;
}

struct func
{
  int& i;
  func(int& i_) : i(i_) {}      // 按引用传递
  void operator() ()
  {
    for (unsigned j=0 ; j<1000000 ; ++j)
    {
        for (unsigned k=0 ; k<1000000 ; ++k){
            do_something(i);           // 1. 潜在访问隐患：悬空引用
        }
    }
  }
};

void oops()
{
  int some_local_state=1;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  my_thread.detach();          // 2. 不等待线程结束
//  my_thread.join();          // 修改为join则可以持续输出值
}                              // 3. 新线程可能还在运行

// do_somthing是一个耗时操作，在运行过程中可能就已经被分离
// 这样就无法继续得到传入my_func()的some_local_state变量的引用

int main(){
    oops();
    return 0;
}

// 单层循环时可以产生输出
// 添加循环增大函数的耗时会不能产生输出，程序直接结束，但不会报错
//
//