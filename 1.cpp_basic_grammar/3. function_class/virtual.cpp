/*
一、多态性 多态性：多态就是在同一个类或继承体系结构的基类与派生类中，用同名函数来实现各种不同的功能。

静态绑定又称静态联编:
    是指在编译程序时就根据调用函数提供的信息，把它所对应的具体函数确定下来，
    即在编译时就把调用函数名与具体函数绑定在一起。

动态绑定又称动态联编:
    是指在编译程序时还不能确定函数调用所对应的具体函数
    只有在程序运行过程中才能够确定函数调用所对应的具体函数，即在程序运行时才把调用函数名与具体函数绑定在一起。

编译时多态性： ---静态联编(连接)----
    系统在编译时就决定如何实现某一动作,即对某一消息如何处理.
    静态联编具有执行速度快的优点.在C++中的编译时多态性是通过函数重载和运算符重载实现的。

运行时多态性： ---动态联编(连接)----
    系统在运行时动态实现某一动作,即对某一消息在运行过程实现其如何响应.
    动态联编为系统提供了灵活和高度问题抽象的优点,在C++中的运行时多态性是通过继承和虚函数实现的。

二、虚函数

虚函数的意义

1、基类与派生类的赋值相容

    在需要基类对象的任何地方，都可以使用公有派生类的对象来代替。
    因为，通过公有继承，除了构造函数和析构函数外，派生类保留了基类其他的所有的成员。
    那么，派生类就具有基类的全部功能，凡是基类能够实现的功能，公有派生类都能实现。

    派生类对象可以赋值给基类对象。 派生类对象的地址可以赋值给指向基类对象的指针。 派生类对象可以作为基类对象的引用。 
    赋值相容的问题： 
        不论哪种赋值方式，都只能通过基类对象（或基类对象的指针或引用）访问到派生类对象从基类中继承到的成员， 
        不能借此访问派生类定义的成员。

2、虚函数使得可以通过基类对象的指针或引用访问派生类定义的成员。

3.Virtual关键字其实质是告知编译系统，被指定为virtual的函数采用动态联编的形式编译。


三、纯虚函数和抽象类

1.纯虚函数概念？

仅定义函数原型而不定义其实现的虚函数 
    Why pure function? 
    实用角度：占位手段place-holder 
    方法学：接口定义手段，抽象表达手段 
    How? class X { virtual ret_type func_name (param) = 0; } 
    
2.抽象类概念？

What is an abstract class? 包含一个或多个纯虚函数的类 
Using abstract class 不能实例化抽象类 但是可以定义抽象类的指针和引用 
Converting abstract class to concrete class 定义一个抽象类的派生类 定义所有纯虚函数

*/

#include <iostream>
using namespace std;
// 从基类继承的成员将访问到派生类版本
namespace derived
{
    class B
    {
    public:
        void f() { g(); } // 从基类继承的成员,访问的是派生类版本
        virtual void g() { cout << "B::g"; }
    };
    class D : public B
    {
    public:
        void g() { cout << "D::g\n"; }
    };
    void test()
    {
        D d;
        d.f();
    }
} // namespace derived

// 基类和派生类的赋值兼容
namespace compatible
{
    class father
    {
    public:
        father() {}
        father(int a) : _a(a) {}
        void set(int b) { _a = b; }
        int _a;
        void show() { cout << "father = " << _a << endl; }
    };
    class son : public father
    {
    public:
        son(int a) : father(a), y(a) {}
        void show() { cout << "son = " << _a << endl; }
        void show_y() { cout << "son = " << y << endl; }
        int y;
    };

    void test()
    {
        cout << "派生类对象可以赋值给基类对象" << endl;
        son a(1);
        father b;
        b = a;    // 将派生类对象赋值给基类
        b.show(); // b没有show_y方法
        a.show();
        cout << "派生类对象的地址可以赋值给指向基类对象的指针" << endl;
        father *fa;
        son s(10);
        fa = &s;
        fa->show();
        s.show();
        fa->set(9);
        fa->show();
        s.show();
        cout << "派生类对象可以作为基类对象的引用" << endl;
        son s2(11);
        father &fb = s2;
        fb.show();
        fb.set(12);
        fb.show();
        s2.show();
    }
} // namespace compatible

// 虚函数例子
/*
4.虚函数的虚特征：基类指针指向派生类的对象时，通过该指针访问其虚函数将调用派生类的版本。

一旦将某个成员函数声明为虚函数后，它在继承体系中就永远为虚函数了
如果基类定义了虚函数，当通过基类指针或引用调用派生类对象时，将访问到它们实际所指对象中的虚函数版本。

只有通过基类对象的指针和引用访问派生类对象的虚函数时，才能体现虚函数的特性。
派生类中的虚函数要保持其虚特征，必须与基类虚函数的函数原型完全相同，否则就是普通的重载函数，与基类的虚函数无关。
派生类通过从基类继承的成员函数调用虚函数时，将访问到派生类中的版本。

只有类的非静态成员函数才能被定义为虚函数，类的构造函数和静态成员函数不能定义为虚函数。
原因是虚函数在继承层次结构中才能够发生作用，而构造函数、静态成员是不能够被继承的。

内联函数也不能是虚函数。因为内联函数采用的是静态联编的方式，而虚函数是在程序运行时才与具体函数动态绑定的，
采用的是动态联编的方式，即使虚函数在类体内被定义，C++编译器也将它视为非内联函数。 \
*/
namespace virtual_fun
{
    class A
    {
    public:
        void f(int i) { cout << "A::f()" << endl; };
    };
    class B : public A
    {
    public:
        virtual void f(int i) { cout << "B::f()" << endl; }
    };
    class C : public B
    {
    public:
        // virtual void f(int i) { cout << "C::f()" << endl; }
        void f(int i) { cout << "C::f()" << endl; }
    };
    //一旦将某个成员函数声明为虚函数后，它在继承体系中就永远为虚函数了
    class D : public C
    {
        // public:
        //     void f(int) { cout << "D::f()" << endl; }
    };
    void test()
    {
        A *pA, a;
        B *pB, b;
        C c;
        D d;
        pA = &a;
        pA->f(1); //调用A::f
        pB = &b;
        pB->f(1); //调用B::f
        pB = &c;
        pB->f(1); //调用C::f
        pB = &d;
        pB->f(1); //调用D::f
    }
} // namespace virtual_fun

namespace virtual_fun_example
{
    class Employee
    {
    public:
        Employee(string name, string id);
        string getName();
        string getId();
        float getSalary();
        virtual void print();

    private:
        string Name;
        string Id;
    };
    Employee::Employee(string name, string id)
    {
        Name = name;
        Id = id;
    }
    string Employee::getName()
    {
        return Name;
    }
    string Employee::getId()
    {
        return Id;
    }
    float Employee::getSalary()
    {
        return 0.0;
    }
    void Employee::print()
    {
        cout << "姓名：" << Name << "\t"
             << "编号：" << Id << endl;
    }

    class Manager : public Employee
    {
    public:
        Manager(string name, string id, float s = 0.0) : Employee(name, id)
        {
            weeklySalary = s;
        }
        void setSalary(float s) { weeklySalary = s; } //设置经理的周薪
        float getSalary() { return weeklySalary; }    //获取经理的周薪
        void print()
        { //打印经理姓名、身份证、周薪
            cout << "经理：" << getName() << "\t\t 编号: " << getId() << "\t\t 周工资: " << getSalary() << endl;
        }

    private:
        float weeklySalary; //周薪
    };

    void test()
    {
        Employee e("小米", "NO0001"), *pM;
        Manager m("小汪", "NO0002", 128);
        m.print();
        pM = &m;
        pM->print();
        Employee &rM = m;
        rM.print();
        // e.print();
    }
} // namespace virtual_fun_example

/*
5.基类析构函数几乎总是为虚析构函数。 
    why? 假定使用delete和一个指向派生类的基类指针来销毁派生类对象，
    如果基类析构函数不为虚,就如一个普通成员函数，delete函数调用的就是基类析构函数。
    在通过基类对象的引用或指针调用派生类对象时，将致使对象析构不彻底！
*/
namespace virtual_destructor
{
    class A
    {
    public:
        ~A()
        {
            cout << "call A::~A()" << endl;
        }
    };
    class B : public A
    {
        char *buf;

    public:
        B(int i) { buf = new char[i]; }
        ~B()
        {
            delete[] buf;
            cout << "call B::~()" << endl;
        }
    };
    void test()
    {

        A *a = new B(10);
        delete a;
    }
} // namespace virtual_destructor


/*
3.C++对抽象类具有以下限定

抽象类中含有纯虚函数，由于纯虚函数没有实现代码，所以不能建立抽象类的对象。
抽象类只能作为其他类的基类，可以通过抽象类对象的指针或引用访问到它的派生类对象，实现运行时的多态性。
如果派生类只是简单地继承了抽象类的纯虚函数，而没有重新定义基类的纯虚函数，则派生类也是一个抽象类。
*/
namespace abstract_class
{
    class Figure
    {
    protected:
        double x, y;

    public:
        void set(double i, double j)
        {
            x = i;
            y = j;
        }
        virtual void area() = 0; // 纯虚函数
    };

    class Triangle : public Figure
    {
    public:
        void area()
        {
            cout << "三角形面积：" << x * y * 0.5 << endl;
        }
    };

    class Rectangle : public Figure
    {
    public:
        void area()
        {
            cout << "这是矩形，它的面积是：" << x * y << endl;
        }
    };

    void test()
    {
        //定义抽象类指针
        Figure *pF = nullptr;
        // Figure f1; 抽象类不能被实例化
        Rectangle r;
        Triangle t;
        t.set(10, 20);
        pF = &t;
        pF->area();
        r.set(10, 20);
        pF = &r;
        pF->area();
        //定义抽象类引用
        Figure &rF = t;
        rF.set(20, 20);
        rF.area();
    }
} // namespace abstract_class

int main()
{
    cout << "========" << endl;
    derived::test();
    cout << "========" << endl;
    compatible::test();
    cout << "========" << endl;
    virtual_fun::test();
    cout << "========" << endl;
    virtual_fun_example::test();
    cout << "========" << endl;
    virtual_destructor::test();
    cout << "========" << endl;
    abstract_class::test();
    return 0;
}