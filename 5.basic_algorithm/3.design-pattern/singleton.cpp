/*
    单例模式：
        * 这个类只能有一个实例
        * 它必须自己创建这个实例
        * 它必须自己向整个系统提供这个实例
    实现：
        私有的构造
        getInstance返回唯一单例
*/

// 1. 基本实现

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <mutex>
#define THREAD_NUM 5
using namespace std;

namespace basic
{
    class Singleton
    {
    public:
        static Singleton *getInstance()
        {
            if (instance == nullptr)
            {
                sleep(1); // 模拟耗时操作
                instance = new Singleton();
            }
            return instance;
        }

    private:
        Singleton()
        {
            cout << "创建新的实例" << endl;
        };
        static Singleton *instance;
    };
    Singleton *Singleton::instance = nullptr;
} // namespace basic

namespace advance
{
    class Singleton
    {
    public:
        static Singleton *getInstance()
        {
            if (instance == nullptr)
            {
                m_mutex.lock();
                if (instance == nullptr)
                {
                    sleep(1); // 模拟耗时操作, 这部分应当尽快且干净
                    instance = new Singleton();
                }
                m_mutex.unlock();
            }
            return instance;
        }
    private:
        Singleton()
        {
            cout << "创建新的实例" << endl;
        };
        static Singleton *instance;
        static mutex m_mutex;
    };

    Singleton *Singleton::instance = nullptr;
    std::mutex Singleton::m_mutex;
} // namespace advance

// 函数调用约定
// 1. 参数从右向左压入堆栈
// 2. 函数被调用者修改堆栈
// 3. 编译器中函数名自动加前导的下划线
namespace test
{
    // using namespace basic; // 非线程安全
    using namespace advance; // 线程安全
    void *CallSingleton(void *pPM) // 传参
    {
        Singleton *s = Singleton::getInstance();
        int nThreadNum = *(int *)pPM;
        printf("线程编号为%d\n", nThreadNum);
    }

    void thread_test()
    {
        int threadNum = 0;
        pthread_t tids[THREAD_NUM];
        while (threadNum < THREAD_NUM)
        {
            // 如果构造太快可能看不出效果，故添加sleep(1)模拟耗时操作
            int ret = pthread_create(&tids[threadNum], NULL, CallSingleton, &threadNum);
            if (ret != 0)
            {
                cout << "pthread_create error: error_code=" << ret << endl;
            }
            threadNum++; // 线程编号的更新不正确
        }
        pthread_exit(NULL);
    }
} // namespace test

int main()
{
    // basic::Singleton *s1 = basic::Singleton::getInstance();
    // basic::Singleton *s2 = basic::Singleton::getInstance();
    // basic::Singleton *s3 = basic::Singleton::getInstance();
    // advance::Singleton *s3 = advance::Singleton::getInstance(); // 同一个命名空间下的static Singleton是同一个
    test::thread_test();
    return 0;
}