/*
 * @Author: Yogurt Suee
 * @Date: 2020-02-19 17:32:35
 * @LastEditors: Yogurt Suee
 * @LastEditTime: 2020-02-19 18:02:28
 * @Description: 多线程的启动
 */

#include <iostream>
#include <thread>

// 构造std::thread对象可以启动线程

// 构造方法有以下几种：

// 1. 一般方案，传入函数名

namespace type1{

    void hello()  //②
    {
    std::cout << "Hello Concurrent World, I`m No 1\n";
    }

    // std::thread my_thread(hello);
}

// 2. 为创建多个函数实例作准备

namespace type2{

    void hello()  //②
    {
    std::cout << "Hello Concurrent World, I`m No 2\n";
    }

    class background_task
    {
        public:
        void operator()() const
        {
            hello();
        }
    };

    // background_task f;
    // std::thread my_thread(f);
}

// 3. Lambda表达式

namespace type3{

    void hello()  //②
    {
    std::cout << "Hello Concurrent World, I`m No 3\n";
    }

    // std::thread my_thread([]{
    // hello();
    // });

}


int main(){
 
    type2::background_task f;
    std::thread my_thread_2(f);

    my_thread_2.join();

    std::thread my_thread_3([]{
    type3::hello();
    });

    my_thread_3.join();

    return 0;
}
