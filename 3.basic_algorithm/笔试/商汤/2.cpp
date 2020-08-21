#include<bits/stdc++.h>
using namespace std;
/*
统计Good个数 不允许重复使用 乱写的 40%
一遍计数应该就可以
*/
int main(){
    string input;
    getline(cin,input);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(auto v:input){
        if(v=='d')
            cnt1++;
        if(v=='G')
            cnt2++;
        if(v=='o')
            cnt3++;
    }
    int res = max(cnt1, max(cnt2,cnt3/2));
    cout<<res<<endl;
    return 0;
}