<!--
 * @Author: Yogurt Suee
 * @Date: 2020-02-19 17:25:17
 * @LastEditors: Yogurt Suee
 * @LastEditTime: 2020-02-19 20:32:05
 * @Description: file content
 -->
# 4. C++并发编程笔记

## 第1章

[第一个c++多线程程序](list-1-1.cpp)

## 第2章

### 2.1 线程管理的基础

[多线程的3种启动方式](list-2-1-01.cpp)

[处理函数已经结束，线程依旧访问局部变量的情况](list-2-1-02.cpp)：测试成功，join住子线程可以完成

[特殊情况下的等待，RAII机制](list-2-1-03.cpp)：测试失败，应该是异常抛出的问题，总是让程序崩溃

[后台线程（守护线程）](list-2-1-04.cpp)：后台线程一般有什么功能呢

### 2.2 向线程函数传递参数

