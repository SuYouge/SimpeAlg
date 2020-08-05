#include <functional>
#include <iostream>
#include <memory>
#include <stdio.h>

using namespace std;

/*
    使用回调函数，应先区分谁是用户，谁是库提供方。
    由用户方实现回调函数，并将回调函数以某种形式注册到库提供方，
    库提供方再在特定事件或条件发生时调用该回调函数
*/

/*
    回调函数要先有一个普通函数(用户实现)，
    再设计一个对应的函数原型(库)。
    再设计一个注册函数(库)
*/

namespace c_style_callback {

// 定义函数原型
// 指向函数的指针类型
// 回调函数， 当有多个参数时， 可以定义一个结构体
// 回调上下文， 在C中传入nullptr， 在C++ 中传入对象指针
typedef void (*CallbackFun)(double height, void *contex); // 这部分是C++
CallbackFun m_pCallback;
// 定义回调函数
// height 参数
// contex 上下文
void onHeight(double height, void *contex) { // 由用户实现
    cout << "current height is " << height << endl;
}
void onWidth(double width, void *contex) { // 由用户实现
    cout << "current width is " << width << endl;
}

// 定义注册回调函数
// 特点是传不同的指针进去就可以对相同的环境进行不同的处理
void registCallback(CallbackFun callback, void *contex) {
    double h = 100; // 完成工作后调用回调
    callback(h, NULL);
}
// 延迟调用
void registDelayCallback(CallbackFun callback, void *contex) {
    m_pCallback = callback;
}
void printDimension(double dim) { m_pCallback(dim, NULL); }
void test() {
    registCallback(onHeight, NULL);
    registCallback(onWidth, NULL);
    // 注册
    registDelayCallback(onHeight, NULL);
    double h = 99;
    printDimension(99);
}
} // namespace c_style_callback

namespace c98_style_callback {
typedef void (*CallbackFun)(double height, void *contex); // 这部分是C++
// 由库提供的回调原型和类
class Callback {
  public:
    Callback(){};
    ~Callback(){};
    void TestCallBack(int height, void *contex);
    CallbackFun registerFun;
};
// 由库提供的注册
void Callback::TestCallBack(int height, void *contex) {
    registerFun(height, NULL);
}

// 用户实现static的回调函数
class getDim {
  public:
    getDim();
    ~getDim(){};
    static void onHeight(double height, void *contex);

  private:
    std::shared_ptr<Callback> m_Callback; // 保存一个库提供的callback对象指针
};
getDim::getDim() {
    m_Callback = make_shared<Callback>();
    m_Callback->registerFun = onHeight;
    m_Callback->TestCallBack(50, nullptr);
}

// 实现回调函数
void getDim::onHeight(double height, void *contex) {
    cout << "current height is " << height << endl;
}
void test() { getDim height; }
} // namespace c98_style_callback

namespace c11_style_callback {
typedef void (*PrintName)(string strName);
enum CallType {
    NAME,
    AGE,
    GRADE,
};

// 应该单独拿到一个头文件中声明, 这里采用c11的第二种形式会有前向引用问题
class CallBack { // 库实现
  public:
    CallBack(){};
    ~CallBack(){};

  public:
    void TestCallBack(CallType type);

  public:
    PrintName m_PrintName;          // 指针类型
    function<void(int)> m_PrintAge; // C11 写法1, 保留一个接口
};

void CallBack::TestCallBack(CallType type) {
    switch (type) {
    case NAME:
        m_PrintName(string("name"));
        break;
    case AGE:
        m_PrintAge(100);
        break;
    // case GRADE: {
    //     function<void(int)> printGrade = // c11 style 2,
    //     不用成员，用起来可能不太方便？
    //         bind(BaseCall::onPrintGrade, placeholders::_1); // 前向引用问题
    //     printGrade(2019);
    // } break;
    default:
        break;
    }
}

class BaseCall { // 用户实现
  public:
    BaseCall();
    ~BaseCall(){};

  public:
    static void onPrintName(string strName);
    static void onPrintAge(int nAge);
    static void onPrintGrade(int);

  private:
    std::shared_ptr<CallBack> m_CallBack;
};

BaseCall::BaseCall() {
    m_CallBack = make_shared<CallBack>(); // callback用户接口
    m_CallBack->m_PrintName = onPrintName;
    m_CallBack->m_PrintAge =
        bind(BaseCall::onPrintAge,
             placeholders::_1); // c11 style 1， 向保留的接口传入函数对象

    m_CallBack->TestCallBack(NAME);
    m_CallBack->TestCallBack(AGE);
    m_CallBack->TestCallBack(GRADE);
}
void BaseCall::onPrintName(string strName) {
    printf("姓名： %s\n", strName.c_str());
}

void BaseCall::onPrintAge(int nAge) { printf("年龄： %d\n", nAge); }

void BaseCall::onPrintGrade(int nGrade) { printf("班级：%d\n", nGrade); }

void test() { BaseCall bc; }

} // namespace c11_style_callback

int main(int argc, char **argv) {
    c_style_callback::test();
    c98_style_callback::test();
    c11_style_callback::test();
    return 0;
}