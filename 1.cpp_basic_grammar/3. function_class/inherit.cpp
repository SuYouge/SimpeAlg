/*
一、公有继承 
    1.基类中protected的成员 类内部：可以访问 类的使用者：不能访问 类的派生类成员：可以访问 
    2.派生类不可访问基类的private成员 
    3.派生类可访问基类的protected成员 
    4.派生类可访问基类的public成员

二、私有继承 派生类不可访问基类的任何成员与函数

三、保护继承 派生方式为protected的继承称为保护继承，在这种继承方式下， 
    基类的public成员在派生类中会变成protected成员， 
    基类的protected和private成员在派生类中保持原来的访问权限 
    注意点：当采用保护继承的时候，由于public成员变为protected成员，因此类的使用者不可访问！而派生类可访问！

四、派生类对基类成员的访问形式 
    1.通过派生类对象直接访问基类成员 
    2.在派生类成员函数中直接访问基类成员 
    3.通过基类名字限定访问被重载的基类成员名
*/

#include <iostream>
using namespace std;

namespace public_inherit
{
    class base
    {
    private:
        int x;

    public:
        void setx(int n) { x = n; }
        int getx() { return x; }
        void showx() { cout << x << endl; }
    };
    //派生类
    class derived : public base
    {
    private:
        int y;

    public:
        void sety(int n) { y = n; }
        void sety() { y = getx(); } // 派生类不可直接访问基类的private成员，可通过基类的共有成员函数访问
        void showy()
        {
            cout << y << endl;
        }
    };

    void test()
    {
        derived obj;
        obj.setx(10);
        obj.sety(20);
        obj.showx();
        obj.showy();
        obj.sety();
        obj.showx();
        obj.showy();
    }

} // namespace public_inherit

namespace private_inherit
{
    class Base
    {
        int x;

    public:
        void setx(int n) { x = n; }
        int getx() { return x; }
        void showx() { cout << x << endl; }
    };
    //私有继承
    //基类的中的public成员在派生类中是private, private成员在派生类中不可访问。
    class derived : private Base
    {
        int y;

    public:
        void sety(int n) { y = n; }
        void setxx(int n) { setx(n); } // 只能通过共有方法设置与访问
        void sety()
        {
            y = getx();
            cout << "getting x " << endl;
        }
        void showy() { cout << y << endl; }
    };
    void test()
    {
        derived obj;
        // obj.setx(10); //cannot access
        obj.sety(20);
        obj.showy();
        obj.setxx(10);
        obj.sety();
        // obj.showx(); //cannot access
        obj.showy();
    }
} // namespace private_inherit

/*
派生方式为protected的继承称为保护继承，在这种继承方式下，
基类的public成员在派生类中会变成protected成员，
基类的protected和private成员在派生类中保持原来的访问权限
*/
namespace protected_inherit
{
    class Base
    {
        int x;

    protected:
        int getx() { return x; }

    public:
        void setx(int n) { x = n; }
        void showx() { cout << x << endl; }
    };
    class Derived : protected Base
    {
        int y;

    public:
        void sety(int n) { y = n; }
        void sety() { y = getx(); } //访问基类的保护成员
        void showy() { cout << y << endl; }
    };
    void test()
    {
        Derived obj;
        // obj.setx(10);    //错误
        obj.sety(20);
        // obj.showx();	 //错误，
        obj.showy();
    }
} // namespace protected_inherit

namespace protected_member
{
    class B
    {
    private:
        int i;

    protected:
        int j;

    public:
        int k;
    };
    class D : public B
    {
    public:
        void f()
        {
            // i = 1; //cannot access 派生类不可访问基类私有成员
            // j = 2; //派生类可以访问基类保护成员
            k = 3;
        }
    };
    void test()
    {
        B b;
        // b.i = 1; //cannot access 私有成员，类的使用者不能访问
        // b.j = 2; //cannot access 保护成员，类的使用者不能访问
        b.k = 3;
    }
} // namespace protected_member

int main()
{
    cout << "========" << endl;
    public_inherit::test();
    cout << "========" << endl;
    private_inherit::test();
    cout << "========" << endl;
    protected_inherit::test();
    cout << "========" << endl;
    protected_member::test();
    return 0;
}