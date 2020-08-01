#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
    set<int> setTemp;

    setTemp.insert(3);
    setTemp.insert(1);
    setTemp.insert(2);
    setTemp.insert(1);

    set<int>::iterator it;
    for (it = setTemp.begin();it != setTemp.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
