#include<iostream>
/*
尽管使用了前向引用声明，但是在提供一个完整的类声明之前，不能声明该类的对象，
也不能在内联成员函数中使用该类的对象。
*/

// class Fred;	//前向引用声明
// class Barney {
//    Fred x;	//错误：类Fred的声明尚不完善,field ‘x’ has incomplete type ‘Fred’
// };
// class Fred {
//    Barney y;
// };

// class Fred;	//前向引用声明
 
// class Barney {
//  public:
//    void method()
//    {
//      x->yabbaDabbaDo();	//错误：Fred类的对象在定义之前被使用,invalid use of incomplete type ‘class Fred’
//    }
//  private:
//    Fred* x;   //正确，经过前向引用声明，可以声明Fred类的对象指针
//  };

// class Fred {
//  public:
//    void yabbaDabbaDo();
//  private:
//    Barney* y;
// }; 

int main(){
    Barney a;

    return 0;
}