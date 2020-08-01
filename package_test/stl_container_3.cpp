#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    map<int, string> mapTemp;
    mapTemp.insert({5,"San Zhang"});
    mapTemp.insert({3,"Si Li"});
    mapTemp.insert({4,"Wang"});

    map<int,string>::iterator it;
    for (it = mapTemp.begin();it != mapTemp.end();it++)
    {
        printf("ID: %d Name: %s \n",(*it).first,(*it).second.c_str());
    }
    return 0;
}
