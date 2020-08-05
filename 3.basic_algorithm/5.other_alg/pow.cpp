#include <iostream>
using namespace std;

/*
    b>>=1不停移位，基不停增加
    b&1提取最后一位
*/


int poww(int a,int b){
    int res = 1, base = a;
    while(b!=0){
        if(b&1!=0)
            res*=base; // 3.
        base*=base; // 1.
        b>>=1; // 2.
    }
    return res;
}

int main(){
    cout<<poww(2,11)<<endl;
    return 0;
}