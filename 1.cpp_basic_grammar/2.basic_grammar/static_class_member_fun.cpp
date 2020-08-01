/*
知识点：
静态成员函数
1. 类外代码可以使用类名和作用域操作符来调用静态成员函数。
2. 静态成员函数只能引用属于该类的静态数据成员或静态成员函数。
*/
#include <iostream>
using namespace std;
namespace test1
{

    class Application
    {
    public:
        static void f();
        static void g();

    private:
        static int global;
    };

    int Application::global = 0;

    void Application::f()
    {
        global = 5;
    }

    void Application::g()
    {
        cout << global << endl;
    }
} // namespace test1

namespace test2
{
    class A
    {
    public:
        static void f(A a);
    private:
        int x{1};
    };
    void A::f(A a)
    {
        //静态成员函数只能引用属于该类的 静态数据成员 或 静态成员函数 。
        // cout<<x; //对x的引用是错误的
        cout << a.x; //正确
    }

} // namespace test2
int main()
{
    test1::Application::f();
    test1::Application::g();

    test2::A a;
    a.f(test2::A());

    return 0;
}