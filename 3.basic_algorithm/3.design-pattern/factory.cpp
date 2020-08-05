/*
    工厂方法：
        简单工厂添加新产品需要修改工厂类，违背了开闭原则。
        工厂方法模式中不再使用工厂类统一创建所有的具体产品，
        而是针对不同的产品设计了不同的工厂，每一个工厂只生产特定的产品
    工厂方法模式：
        定义一个用于创建对象的接口，但是让子类决定将哪一个类实例化。
        工厂方法模式让一个类的实例化延迟到其子类。
*/

/*
    角色：
        * 抽象工厂：所有生产具体产品的工厂类的基类，提供工厂类的公共方法；
        * 具体工厂：生产具体的产品；
        * 抽象产品：所有产品的基类，提供产品类的公共方法；
        * 具体产品：具体的产品类
*/

/*
    优点：
        隐藏创建产品的细节，工厂自主决定创建何种产品，新产品加入时无需修改原有代码，增强了系统的可扩展性
    缺点：
        添加新产品时成对增加了新的产品工厂
        客户端代码中用到了工厂和产品引入的抽象层（AbstractFactory和AbstractSportProduct）
*/

#include <iostream>
using namespace std;

/*
    定义抽象产品类，不提供实现
*/
class AbstractSportProduct
{
public:
    AbstractSportProduct() {}
    // 抽象方法
    void printName(){};
    void play(){};
};

/*
    定义是三个具体产品类
*/
class Basketball : public AbstractSportProduct
{
public:
    Basketball()
    {
        printName();
        play();
    }
    // 具体实现方法
    void printName()
    {
        cout << "Get Basketball" << endl;
    }
    void play()
    {
        cout << "Play Basketball" << endl;
    }
};

class Football : public AbstractSportProduct
{
public:
    Football()
    {
        printName();
        play();
    }
    // 具体实现方法
    void printName()
    {
        cout << "Get Football" << endl;
    }
    void play()
    {
        cout << "Play Football" << endl;
    }
};

class Volleyball : public AbstractSportProduct
{
public:
    Volleyball()
    {
        printName();
        play();
    }
    // 具体实现方法
    void printName()
    {
        cout << "Get Volleyball" << endl;
    }
    void play()
    {
        cout << "Play Volleyball" << endl;
    }
};

/*
    定义抽象工厂类
*/
class AbstractFactory
{
public:
    virtual AbstractSportProduct *getSportProduct() = 0;
};

/*
    定义三个具体工厂类
*/

class BasketballFactory : public AbstractFactory
{
public:
    BasketballFactory()
    {
        cout << "Basketball Factory" << endl;
    }
    AbstractSportProduct *getSportProduct()
    {
        cout << "Producting Basketball"<<endl;
        return new Basketball();
    }
};

class FootballFactory : public AbstractFactory
{
public:
    FootballFactory()
    {
        cout << "Football Factory" << endl;
    }
    AbstractSportProduct *getSportProduct()
    {
        cout << "Producting Football"<<endl;
        return new Football();
    }
};

class VolleyballFactory : public AbstractFactory
{
public:
    VolleyballFactory()
    {
        cout << "Volleyball Factory" << endl;
    }
    AbstractSportProduct *getSportProduct()
    {
        cout << "Producting Volleyball"<<endl;
        return new Volleyball();
    }
};

int main()
{
    cout << "工厂方法模式" << endl;
    AbstractFactory *fac = nullptr;
    AbstractSportProduct *prod = nullptr;
    fac = new BasketballFactory();
    prod = fac->getSportProduct();
    fac = new FootballFactory();
    prod = fac->getSportProduct();
    fac = new VolleyballFactory();
    prod = fac->getSportProduct();
    return 0;
}