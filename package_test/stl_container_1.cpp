#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vecTemp;
    for(int i = 0;i<6;i++)
        vecTemp.push_back(i);
    for(int i = 0;i<vecTemp.size();i++)
        cout<<vecTemp[i]<<" ";
    return 0;
}
