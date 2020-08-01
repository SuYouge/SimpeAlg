/*
多继承下的二义性：在多继承方式下，派生类继承了多个基类的成员，当两个不同基类拥有同名成员时，容易产生名字冲突问题。

虚拟继承引入的原因：重复基类，派生类间接继承同一基类使得间接基类（Person）在派生类中有多份拷贝，引发二义性。

    1、虚拟继承virtual inheritance的定义 
        语法 class derived_class : virtual […] base_class 虚基类virtual base class 
        被虚拟继承的基类 在其所有的派生类中，仅出现一次

    2、虚拟继承的构造次序 虚基类的初始化与一般的多重继承的初始化在语法上是一样的，但构造函数的调用顺序不同； 
        若基类由虚基类派生而来，则派生类必须提供对间接基类的构造（即在构造函数初始列表中构造虚基类，无论此虚基类是直接还是间接基类） 

调用顺序的规定： 
    先调用虚基类的构造函数，
    再调用非虚基类的构造函数 若同一层次中包含多个虚基类,
    这些虚基类的构造函数按它们的说明的次序调用 
    若虚基类由非基类派生而来,则仍然先调用基类构造函数,再调用派生类构造函数 

    3、虚基类由最终派生类初始化 
    在没有虚拟继承的情况下，每个派生类的构造函数只负责其直接基类的初始化。
    但在虚拟继承方式下，虚基类则由最终派生类的构造函数负责初始化。 

在虚拟继承方式下，若最终派生类的构造函数没有明确调用虚基类的构造函数，
编译器就会尝试调用虚基类不需要参数的构造函数（包括缺省、无参和缺省参数的构造函数），
如果没找到就会产生编译错误。
*/

/*
    多继承二义性的解决方案：
        1. 调用时限定
        2. 同名覆盖
        3. 虚拟继承
*/

/*
虚拟继承的使用场合：
    |------->B------->|
    A                 D
    |------->C-------->|
B继承A，C继承A，D继承B和C
*/

#include <iostream>
using namespace std;

namespace virtual_inherit // 同一个基类二义性
{
    class A
    {
    public:
        void vf()
        {
            cout << "I come from class A" << endl;
        }
    };
    class B : public A
    {
    };
    class C : public A
    {
    };
    class D : public B, public C
    {
    public:
        // 二义性出现，不能区分C::vf()和B::vf();
        void vf()
        {
            B::vf();
        }
    };

    void test()
    {
        D d;
        d.vf(); // error
    }
} // namespace virtual_inherit

namespace virtual_inherit_2
{
    class A
    {
    public:
        void vf()
        {
            cout << "I come from class A" << endl;
        }
    };
    class B : virtual public A
    {
    public:
        void vf()
        {
            cout << "I come from class B" << endl;
        }
    };
    class C : virtual public A
    {
    public:
        // void vf()
        // {
        //     cout << "I come from class C" << endl;
        // }
    };
    class D : public B, public C
    {
    };

    void test()
    {
        D d;
        d.vf(); // okay
    }
} // namespace virtual_inherit_2

//
namespace derived_init
{
    class A
    {
        int a;

    public:
        A(int x)
        {
            a = x;
            cout << "Virtual Base A..." << endl;
        }
    };
    class B : virtual public A
    {
    public:
        B(int i) : A(i) { cout << "Virtual Base B..." << endl; }
    };
    class C : virtual public A
    {
        int x;

    public:
        C(int i) : A(i)
        {
            cout << "Constructing C..." << endl;
            x = i;
        }
    };
    class ABC : public B, public C // 从左向右
    {
    public:
        //虚基类由最终派生类初始化
        ABC(int i, int j, int k) : C(i), B(j), A(i) //L1，这里必须对A进行初始化
        {
            cout << "Constructing ABC..." << endl;
        }
    };
    void test()
    {
        ABC obj(1, 2, 3);
    }
} // namespace derived_init

/*
    先调用虚基类的构造函数，再调用非虚基类的构造函数 若同一层次中包含多个虚基类,
    这些虚基类的构造函数按它们的说明的次序调用 
    若虚基类由非基类派生而来,则仍然先调用基类构造函数,再调用派生类构造函数 
*/
namespace virtual_base_call
{
    class preA
    {
    public:
        int a;
        preA() { cout << "Constructing preA" << endl; }
    };
    class A : public preA
    {
        int a;

    public:
        A() { cout << "Constructing A" << endl; }
    };
    class B
    {
    public:
        B() { cout << "Constructing B" << endl; }
    };
    // 先把所有虚基类构造出来
    class B1 : public B, virtual public A // 1. B A B1
    {
    public:
        B1(int i) { cout << "Constructing B1" << endl; }
    };
    class B2 : public A, virtual public B // 2. A B2
    {
    public:
        B2(int j) { cout << "Constructing B2" << endl; }
    };
    class D : public B1, public B2
    {
    public:
        D(int m, int n) : B1(m), B2(n) { cout << "Constructing D" << endl; }
        A a; // 先构造成员再构造自身（调用构造函数）
    };

    void test()
    {
        D d(1, 2);
    }
} // namespace virtual_base_call

// 二义性的解决
namespace solve_ambiguous
{
    // 二义性的出现
    // 1. 不同基类的同名函数
    class father_1
    {
    public:
        void call() { cout << "im f1" << endl; }
    };
    class father_2
    {
    public:
        void call() { cout << "im f2" << endl; }
    };
    class son : public father_1, public father_2
    {
    public:
        void call()
        { // 解决方法2：同名覆盖
            father_1::call();
        }
    };
    // 2. 共同基类的同一个函数
    class son_1 : virtual public father_1
    { // 解决方法3：虚拟继承
    };
    class son_2 : virtual public father_1
    {
    };
    class grand_son : public son_1, public son_2
    {
    public:
        // void call(){
        //     son_1::call();
        // }
    };
    void test()
    {
        son s;
        grand_son gs;
        gs.call(); // "solve_ambiguous::grand_son::call" is ambiguous
        s.call();  // "solve_ambiguous::son::call" is ambiguous
        son s2;
        grand_son gs2;
        s2.father_1::call(); // 解决方法1：调用时类名限定
        gs2.son_1::call();
    }
} // namespace solve_ambiguous

int main()
{
    cout << "========" << endl;
    virtual_inherit::test();
    cout << "========" << endl;
    virtual_inherit_2::test();
    cout << "========" << endl;
    derived_init::test();
    cout << "========" << endl;
    virtual_base_call::test();
    cout << "========" << endl;
    solve_ambiguous::test();
    return 0;
}