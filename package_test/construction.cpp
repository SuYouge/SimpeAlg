#include <iostream>
using namespace std;

class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        //Line();//构造函数
        Line(double len);//析构函数
        ~Line();
    private:
        double length;
};
//构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回void
//构造函数可以用于为某些成员变量设置初始值
//默认的构造函数不带任何参数
/*
Line::Line(void)
{
    cout<<"Object is being created"<<endl;
};
*/
//构造函数也可以带有参数
/*
Line::Line(double len){
    cout<<"Object is beding created, length = "<<len<<endl;
    length = len;
}*/
//也可以利用初始化字段直接为成员变量赋值
Line::Line(double len): length(len){
    cout<<"Object is beding created, length = "<<len<<endl;
}
/*
 //多个变量的情形
Line::Line(double len1,double len2, double len3): length1(len1),length2(len2), length3(len){
}
 */
void Line::setLength(double len)
{
    length = len;
}
double Line::getLength(void){
//length为private variable
    return length;
}
//析构函数没有参数值，在销毁对象时执行
Line::~Line(void){
    cout<<"Object is being deleted"<<endl;
}
int main(){
    //Line line;
    Line line(10.0);
    cout<<"Length of line : "<<line.getLength()<<endl;
    line.setLength(6.0);
    cout<<"Length of line : "<<line.getLength()<<endl;
    return 0;
};
