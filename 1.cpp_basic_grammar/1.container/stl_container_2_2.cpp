#include <iostream>
#include <set>
#include <string>

using namespace std;

struct People
{
    string name;
    int age;
    bool operator <(const People p ) const
    {
        return age < p.age;
    }
};

int main(int argc, char* argv[])
{
    set<People> setTemp;
    setTemp.insert({"San Zhang",14});
    setTemp.insert({"Si Li",16});
    setTemp.insert({"Wang",10});
    
    set<People>::iterator it;
    for (it = setTemp.begin();it != setTemp.end();it++)
    {
        std:: printf("Name: %s Age: %d\n", (*it).name.c_str(),(*it).age);
    }
    return 0;
}
