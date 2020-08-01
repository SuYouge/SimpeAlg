/*
 * @Author: Yogurt Suee
 * @Date: 2020-02-19 17:20:46
 * @LastEditors: Yogurt Suee
 * @LastEditTime: 2020-02-19 20:01:12
 * @Description:  第一个多线程程序
 */

#include <iostream>
#include <thread>  //①
void hello()  //②
{
    std::cout << "Hello Concurrent World\n"; 
}
int main()
{
    std::thread t(hello);  //③
    t.join();  //④
    return 0;
}

// 注释掉第10行以后运行输出如下,即main在hello运行前就结束了：
// 因为随着main的结束，std::thread对象会被销毁，所以有这样一个报错

//     terminate called without an active exception
//     Hello Concurrent World

// 新线程启动后，初始线程main会自己运行到结束，甚至比新线程运行还早结束，
// 所以需要调用.join，这样会导致调用线程main，等待与std::thread对象相关联的线程，即t
