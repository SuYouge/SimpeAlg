#include <iostream>
#include <string>

using namespace std;

int main(){

    int a, b;

    cin>> a >> b;

    string output = to_string(a+b);

    int len = output.length();

    for(int i =0;i <len ; i++){
        cout<<output[i];
        if(output[i] == '-') continue;
        if((i+1)%3 == len%3 && i!=len-1) cout<<',';
    }

    return 0;
}