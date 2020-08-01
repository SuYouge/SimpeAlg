// CMyString
#include <cstring>
#include <cstdio>
#include <iostream>
// #include <new> // new在堆分配空间

/*
构造函数的类型：
    1. 无参构造函数
    2. 一般构造函数
    3. 赋值构造函数(拷贝赋值,重载赋值) copy assignment operator
    4. 转换构造函数
    5. 拷贝构造函数 copy constructor
Rule of three：
    对指针类型成员
    显式定义：析构函数(destructor)、拷贝构造函数(copy constructor)和重载赋值函数(copy assignment operator)
*/

class CMyString
{
public:
    CMyString(char* pData = nullptr); // 一般构造函数
    CMyString(const CMyString& str); // 拷贝构造
    ~CMyString(void);

    CMyString& operator = (const CMyString& str) throw(); // 赋值构造函数, 保证不抛出任何异常

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char* pData){
    if(pData == nullptr){
        m_pData = new char[1];
        m_pData[0] = '\n';
    }else{
        int length = strlen(pData);
        m_pData = new char[length+1];
        strcpy(m_pData, pData);
        // printf("*******\n");
    }
}


CMyString::CMyString(const CMyString& str){
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1]; // new 失败了会返回一个空指针或者抛出异常终止程序
    // m_pData = nullptr; // 会抛出异常
    strcpy(m_pData, str.m_pData); // dst为空指针会抛出异常
    // printf("=========\n");
}

CMyString::~CMyString(){
    delete[] m_pData;
}

void CMyString::Print(){
    printf("%s", m_pData);
}

// 传引用：提高效率
// 返回引用：连续赋值
// 判断是否为同一个实例

// Basic
// CMyString& CMyString::operator = (const CMyString& str){
//     if(this == &str){ // this 非静态成员函数的隐含形参
//         return *this; // 在类的非静态成员函数中返回类对象本身
//     }

//     delete[] m_pData;
//     m_pData = nullptr;
//     m_pData = new char[strlen(str.m_pData)+1]; // m_pData为空指针时容易导致程序崩溃
//     strcpy(m_pData, str.m_pData); // dst src

//     return *this;
// }

// Adavance
// 赋值构造用到了拷贝构造
CMyString& CMyString::operator = (const CMyString& str) throw(){
    if(this!=&str){
        CMyString strTemp(str); // 拷贝构造一个tmp
        char* ptmp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = ptmp;
        delete ptmp;
        // CMyString strTemp(str); // 拷贝构造一个tmp
    }
    return *this;
}


// 一个赋值给另一个
void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text); // 

    CMyString str2;
    // printf("The actual result is: ");
    // str2.Print();
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    // str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);

    // CMyString str2, str3;
    // str3 = (str2 = str1);

    CMyString str2 = str1; // 没有调用拷贝构造而是拷贝构造,等同于 CMString str2(str1);
    CMyString str3;
    str3 = str2;

    printf("The expected result is: %s.\n", text);
    printf("The expected result is: %s.\n", text);
    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}