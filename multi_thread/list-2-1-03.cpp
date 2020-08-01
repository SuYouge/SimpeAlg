/*
 * @Author: Yogurt Suee
 * @Date: 2020-02-19 18:45:45
 * @LastEditors: Yogurt Suee
 * @LastEditTime: 2020-02-19 20:00:53
 * @Description: 特殊情况下的等待，RAII机制（实际上等待都失败了）
 */

#include <iostream>
#include <thread>
#include <assert.h>

// 模拟情况：当在线程运行之后（主线程中）产生异常，在join()调用之前抛出，就意味着这次调用会被跳过

// 主线程中join之前的报错函数
int error_fun(){
    int a = 1;
    int b = 0;
    // if( b == 0 )
    // {
    //     throw "Division by zero condition!";
    //     return 0;
    // }
    for(int i=9999;i>8999;i--){
        std::cout<<i<<"at error_fun"<<std::endl;
    }
    return 0;
    // return (a/b);
}

// 子线程中将调用的函数
struct func
{
  int& i;
  func(int& i_) : i(i_) {}      // 按引用传递
  void operator() ()
  {
    for (long long j=0 ; j<1000 ; ++j)
    {
        std::cout<<j<<std::endl;           // 1. 潜在访问隐患：悬空引用
    }
  }
};


// 1. 无法正常join的情况
void f1(){
    int some_local_state=11;
    func my_func(some_local_state);
    std::thread t(my_func);
    error_fun(); // 此处报错
    t.join();  // 1
}

// 2. 在报错之前join
void f2()
{
  int some_local_state=11;
  func my_func(some_local_state);
  std::thread t(my_func);
  try
  {
    int a = error_fun(); // 此处报错
  }
  catch(const char* msg)
  {
    t.join();  // 1
    std::cerr << msg << std::endl;
  }
  t.join();  // 2
}

// 3. 主线程和子线程一同进行，子线程可以被join
void f3(){
    int some_local_state=11;
    func my_func(some_local_state);
    std::thread t(my_func);
    try {
        error_fun(); // 此处报错
    }catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    t.join();  // 1
}

// 4. RAII：由于系统的资源不具有自动释放的功能，而C++中的类具有自动调用析构函数的功能。
// 如果把资源用类进行封装起来，对资源操作都封装在类的内部，在析构函数中进行释放资源。
// 当定义的局部变量的生命结束时，它的析构函数就会自动的被调用，如此，就不用程序员显示的去调用释放资源的操作了

class thread_guard
{
    std::thread& t;
    public:
        explicit thread_guard(std::thread& t_):
        t(t_)
        {}
        ~thread_guard()
        {
            if(t.joinable()) // 1
            {
            t.join();      // 2
            }
        }
        thread_guard(thread_guard const&)=delete;   // 3
        thread_guard& operator=(thread_guard const&)=delete;
};

void f4()
{
  int some_local_state=0;
  func my_func(some_local_state);
  std::thread t(my_func);
  thread_guard g(t);
  error_fun();
}    // 4



int main(){

    // f1();  // 子线程不能完成，程序崩溃
    // f2();   // 子线程可以完成，程序崩溃，报错如下
    
    // Division by zero condition!
    // terminate called after throwing an instance of 'std::system_error'
    // what():  Invalid argument

    f3();   // 子线程可以完成，程序不崩溃，除零报错出现在主线程输出之间
    // f4();   // 按理说子线程应该可以完成，但实际不能 没能join

    // 不报错的情况下大家都能完成任务
    
    return 0;

}


