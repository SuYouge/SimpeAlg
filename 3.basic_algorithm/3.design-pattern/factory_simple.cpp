/*
简单工厂的实现流程：
    * 设计一个抽象产品类，它包含一些公共方法的实现
    * 从抽象产品类中派生出多个具体产品类，如篮球类，足球类，排球类，具体产品类中实现具体产品生产的相关代码
    * 设计一个工厂类，工厂类中提供一个生产各种产品的工厂方法，该方法根据传入参数（产品名称）创建不同的具体产品类对象
    * 客户只需要调用工厂类的工厂方法，并传入具体产品参数，即可得到一个具体产品对象
简单工厂定义：
    * 定义一个简单工厂类，它可以根据参数的不同返回不同类的实例，被创建的实例通常都具有共同的父亲

三个角色：
    * 工厂：根据客户提供的具体产品类的参数，创建具体产品实例
    * 抽象产品：具体产品类的基类，包含创建产品的公共方法
    * 具体产品：抽象产品的派生类，包含具体产品特有的实现方法，是简单工厂模式的创建目标
优点：
    * 工厂类提供创建具体产品的方法，并包含一定判断逻辑，客户不必参与产品的创建过程；
    * 客户只需要知道对应产品的参数即可，参数一般简单好记， 如数字、字符或者字符串等。
缺点：
    * 创建新的产品会违背“对扩展开放，对修改关闭”的原则
*/

/*
    定义抽象产品类AbstractProduct，抽象方法不提供实现
*/
#include <iostream>
#include <string>

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
    定义工厂类和工厂方法
*/

class Factory
{
public:
    AbstractSportProduct *getSportProduct(string productName)
    {
        AbstractSportProduct *pro = nullptr; // 基类
        if (productName == "Basketball")
        {
            pro = new Basketball();
        }
        else if (productName == "Football")
        {
            pro = new Football();
        }
        else if (productName == "Volleyball")
        {
            pro = new Volleyball();
        }
        return pro;
    }
};

int main()
{
    cout << "简单工厂模式" << endl;
    // 定义工厂类对象
    Factory *fac = new Factory();
    // 定义抽象类
    AbstractSportProduct *product = nullptr;
    product = fac->getSportProduct("Basketball");
    product = fac->getSportProduct("Football");
    product = fac->getSportProduct("Volleyball");
    return 0;
}