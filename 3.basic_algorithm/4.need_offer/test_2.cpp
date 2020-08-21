#include <iostream>
using namespace std;


void t1(int k, int x){
    cout<<(x%=(k%=5))<<endl;
}

void t2(int k, int x){
    cout<<(x%=(k-k%5))<<endl;
}

void t3(int k, int x){
    cout<<(x%=k-k%5)<<endl;
}

void t4(int k, int x){
    cout<<((x%=k)-(k%=5))<<endl;
}

int main(){

    int k = 7;
    int x = 12;
    t1(7,12);
    t2(7,12);
    t3(7,12);
    t4(7,12);
    return 0;
}