/*
    抽象工厂模式：
        提供一个创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类。

    一个工厂可以提供创建多种相关产品的接口，而无需像工厂方法一样，为每一个产品都提供一个具体工厂。
*/

/*
    四个角色：
        * 抽象工厂：所有生产具体产品的工厂类的基类，提供工厂类的公共方法
        * 具体工厂：生产具体的产品
        * 抽象产品：所有产品的基类，提供产品类公共方法
        * 具体产品：具体的产品类
*/

/*
    优点：
        * 工厂方法用于创建客户所需产品，同时向客户隐藏某个具体产品类将被实例化的细节，用户只需关心所需产品对应的工厂
        * 新加入产品系列时，无需修改原有系统，增强了系统的可扩展性，符合开闭原则。
    缺点：
        * 在已有产品系列中添加新产品时需要修改抽象层代码，对原有系统改动较大，违背开闭原则。
*/

#include <iostream>
using namespace std;
// 抽象产品类 AbstractBall，球类的基类，定义抽象方法play
class AbstractBall
{
public:
    AbstractBall() {}
    // 抽象方法
    void play() {}
};

// 具体产品类， 分别为Basketball和Football，具体实现方法play
class Basketball : public AbstractBall
{
public:
    Basketball()
    {
        play();
    }
    void play()
    {
        cout << "Playing Basketball" << endl;
    }
};

class Football : public AbstractBall
{
public:
    Football()
    {
        play();
    }
    void play()
    {
        cout << "Playing Basketball" << endl;
    }
};

// 抽象产品类
class AbstractShirt
{
public:
    AbstractShirt() {}
    void wearShirt() {}
};

// 具体产品类BasketballShirt和FootballShirt， 具体方法wearShirt

class BasketballShirt : public AbstractShirt
{
public:
    BasketballShirt()
    {
        wearShirt();
    }
    void wearShirt()
    {
        cout << "Basketball Shirt" << endl;
    }
};

class FootballShirt : public AbstractShirt
{
public:
    FootballShirt()
    {
        wearShirt();
    }
    void wearShirt()
    {
        cout << "Football Shirt" << endl;
    }
};

// 抽象工厂类
class AbstractFactory
{
public:
    virtual AbstractBall *getBall() = 0;
    virtual AbstractShirt *getShirt() = 0;
};

class BasketballFactory : public AbstractFactory
{
public:
    BasketballFactory()
    {
        cout << "Basketball Factory" << endl;
    }
    AbstractBall *getBall()
    {
        cout << "Basketball" << endl;
        return new Basketball();
    }
    AbstractShirt *getShirt()
    {
        cout << "getting Basketball shirt" << endl;
        return new BasketballShirt();
    }
};

class FootballFactory : public AbstractFactory
{
public:
    FootballFactory()
    {
        cout << "Football Factory" << endl;
    }
    AbstractBall *getBall()
    {
        cout << "Football" << endl;
        return new Football();
    }
    AbstractShirt *getShirt()
    {
        cout << "getting Football shirt" << endl;
        return new FootballShirt();
    }
};

int main()
{
    cout << "抽象工厂模式" << endl;
    AbstractFactory *fac = nullptr;
    AbstractShirt *shirt = nullptr;
    AbstractBall *ball = nullptr;
    fac = new BasketballFactory();
    shirt = fac->getShirt();
    ball = fac->getBall();
    fac = new FootballFactory();
    shirt = fac->getShirt();
    ball = fac->getBall();
    return 0;
}
