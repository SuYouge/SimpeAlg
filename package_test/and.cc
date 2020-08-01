#include <iostream>
using namespace std;

int main(){

    int i = 1214;
    // interesting 通过位运算：按位与（-2）获得了最接近原数字的偶数
    int output = i &-2;

    cout<<i<<" &-2 =  "<<output<<endl;

    return 0;
}