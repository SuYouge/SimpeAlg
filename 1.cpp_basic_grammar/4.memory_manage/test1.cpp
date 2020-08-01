#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> a;
    cin>>n;
    int tmp;
    for(int i =0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    int resu = 0;
    int output = 0xfffffff;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //if(i==j) continue;
            resu = (a[i]-a[j])/((j+1)-(i+1));
            if(resu<output) output = resu;
        }
    }
    cout<<output<<endl;
    return 0;
}