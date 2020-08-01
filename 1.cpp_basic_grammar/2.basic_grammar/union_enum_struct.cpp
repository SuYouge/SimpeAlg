#include<iostream>
using namespace std;

enum weekday
{
 sun,mon,tue,wed,thu,fri,sat
};

void test_enum(){
    enum weekday wek=sun;
    for(int i=wek;i!=fri;i++)
    {
        cout<<i<<endl;
        cout<<wek+sat<<endl;
    }
}

union uni {
    struct {int x; int y; int z; }p;
    struct {int a; int b; }q;
    int head;
};

void test_union(){
    uni u1{0,0,0};
    cout<<u1.p.x<<" "<<u1.p.y<<" "<<u1.p.z<<endl;
    cout<<u1.q.a<<" "<<u1.q.b<<endl;
    cout<<u1.head<<endl;
    u1.head = 5;
    cout<<u1.head<<endl;
}

struct student{
    int num;
    char name[20];
    char gender;
};

void test_struct(){
    student s={10,"asd",'M'};
    cout<<s.num<<endl;
    cout<<sizeof(s.num)<<endl;
    cout<<sizeof(s.name)<<endl;
    cout<<sizeof(s.gender)<<endl;
    cout<<sizeof(s)<<endl;
}

int main(int argc, char const *argv[])
{
    test_struct();
    // test_union();
    return 0;
}