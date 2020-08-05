/*
    构造函数调用次序
*/

#include <iostream>
using namespace std;

namespace construct_fun_call
{
    class A
    {
        int x;

    public:
        A(int i = 0)
        {
            x = i;
            cout << "A-----" << x << endl;
        }
    };

    class B
    {
        int y;

    public:
        B(int i)
        {
            y = i;
            cout << "B-----" << y << endl;
        }
    };

    class C
    {
        int z;

    public:
        C(int i)
        {
            z = i;
            cout << "C-----" << z << endl;
        }
    };

    class D : public B
    {
    public:
        // 类对象成员的构造 先构造成员 再构造自身（调用构造函数）
        C c1, c2;
        A *a1 = new A(10);
        A a0, a4;
        D() : a4(4), c2(2), c1(1), B(1) //
        {
            cout << "D-----5" << endl;
        }
    };
} // namespace construct_fun_call

/*
    构造和析构顺序
*/

/*
先构造成员
再构造自身（调用构造函数）
*/
namespace construct_member
{
    class A
    {
    public:
        A() { cout << "Constructing A" << endl; }
        ~A() { cout << "Destructing A" << endl; }
    };
    class B
    {
    public:
        B() { cout << "Constructing B" << endl; }
        ~B() { cout << "Destructing B" << endl; }
    };

    class C
    {
    public:
        C() { cout << "Constructing C" << endl; }
        ~C() { cout << "Destructing C" << endl; }
        B b;
        A a;
    };
} // namespace construct_member

// 没有构造函数的派生类
namespace construct_without_derived
{
    class A
    {
    public:
        A() { cout << "Constructing A" << endl; }
        ~A() { cout << "Destructing A" << endl; }
    };
    class B : public A
    {
    public:
        ~B() { cout << "Destructing B" << endl; }
    };
} // namespace construct_without_derived

namespace derived_construct // 派生类构造函数调用顺序
{
    class Base
    {
    private:
        int x;

    public:
        Base(int a)
        {
            x = a;
            cout << "Base constructor x=" << x << endl;
        }
        Base()
        {
            cout << "call Base without param" << endl;
        }
        ~Base()
        {
            cout << "Base destructor..." << endl;
        }
    };
    class Derived : public Base
    {
    private:
        int y;

    public:
        Derived(int a)
        {
            y = a;
            cout << "Derived constructor y=" << y << endl;
        }
        Derived(int a, int b) : Base(a) // 调用基类的构造
        {                               //派生类构造函数的初始化列表
            y = b;
            cout << "Derived constructor y=" << y << endl;
        }
        ~Derived()
        {
            cout << "Derived destructor..." << endl;
        }
    };
} // namespace derived_construct

namespace test
{
    class base_base
    {
    public:
        base_base(int a) { cout << "construct bb" << endl; }
        base_base() { cout << "construct bb without param" << endl; }
    };
    class base : public base_base
    {
    public:
        base(int a) { cout << "construct b" << endl; } // 按照参数调用基类的构造
        int y;
    };
    class derived : public base
    {
    public:
        derived(int a) : base(a) { cout << "construct d" << endl; }
    };
} // namespace test

int main()
{

    cout << "=======" << endl; // 构造函数调用次序
    {
        // 成员构造顺序和定义顺序符合 析构函数的析构顺序与构造相反
        construct_fun_call::D d;
    }
    cout << "=======" << endl;
    {
        construct_member::C c; // 析构
    }
    cout << "=======" << endl;
    {
        construct_without_derived::B b; // 没有构造的派生类
    }
    cout << "=======" << endl;
    {
        derived_construct::Derived d(2, 4); // 派生类构造函数调用顺序
    }
    cout << "=======" << endl;
    {
        derived_construct::Derived d(2); // 派生类构造函数调用顺序
    }
    cout << "=======" << endl;
    {
        test::derived(7); // 派生类给基类传参
    }
    return 0;
}