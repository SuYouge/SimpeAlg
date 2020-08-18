#include <iostream>
#include <string>
#include <algorithm>
using namespace std;





class Solution {
public:

// string plus(string a, string b){
//     if(a.length()<b.length())
//         swap(a,b);
//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());
//     string res;
//     int jinwei = 0;
//     int tmp = 0;
//     for(int i = 0;i<a.length();i++){
//         if(i<b.length()){
//             int tmp = a[i]-'0' + b[i]-'0' + jinwei;
//             res += to_string(tmp%10);
//             jinwei = tmp/10;
//         }
//         else{
//             tmp = a[i]-'0' + jinwei;
//             res += to_string(tmp%10);
//             jinwei = tmp/10;
//         }
//     }
//     if(jinwei != 0){
//         res+=to_string(jinwei);
//     }
//     reverse(res.begin(),res.end());
//     return res;
// }

// 注意length的范围，可能会越界
string plus(string a, string b){
    if(a.length()<b.length())
        swap(a,b);
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
    string res;
    int jinwei = 0;
    int tmp = 0;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    for(int i = a.length() - 1;i >= 0 ;i--){
        int ind = i - (a.length() - b.length());
        // cout<<"index = "<<ind<<endl;
        if(ind >= 0){
            // cout<<"a[i] = "<<a[i]-'0'<<endl;
            // cout<<"b[i] = "<<b[i - (a.length() - b.length())]-'0'<<endl;
            tmp = a[i]-'0' + b[ind]-'0' + jinwei;
            res = to_string(tmp%10) + res;
            jinwei = tmp/10;
        }
        else{
            tmp = a[i]-'0' + jinwei;
            res = to_string(tmp%10) + res;
            jinwei = tmp/10;
        }
    }
    if(jinwei != 0){
        res = to_string(jinwei) + res;
    }
    // reverse(res.begin(),res.end());
    return res;
}


public:
    string cheng(char a, string num){
        if(a == '0') return "0";
        string res;
        int jinwei = 0;
        int n1 = a-'0';
        // reverse(num.begin(), num.end());
        for(auto it = num.rbegin(); it!=num.rend();it++){
            int tmp = (*it-'0') * n1 + jinwei;
            jinwei = tmp/10;
            res = to_string(tmp%10) + res;  
        }
        if(jinwei!=0)
            res = to_string(jinwei) + res;  
        // reverse(res.begin(), res.end());
        return res;
    }    
    
    // string cheng(char a, string num){
    //     if(a == '0') return "0";
    //     string res;
    //     int jinwei = 0;
    //     int n1 = a-'0';
    //     reverse(num.begin(), num.end());
    //     for(auto n :num){
    //         int tmp = (n-'0') * n1 + jinwei;
    //         jinwei = tmp/10;
    //         res += to_string(tmp%10);  
    //     }
    //     if(jinwei!=0)
    //         res += to_string(jinwei);  
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

public:
    string multiply(string num1, string num2) {
        if(num1.length() < num2.length())
            swap(num1, num2); // 保证num1最长
        reverse(num2.begin(), num2.end());
        string output;
        string res;
        for(int i = 0;i<num2.length();i++){
            output = cheng(num2[i], num1);
            // cout<<num2[i] <<" * "<<num1<< " = "<< output<<endl;
            for(int j = 0; j<i ;j++){
                output =  output + "0";
            }
            cout<<"output = "<<output<<endl;
            res = plus(res, output);
        }
        return res;
    }
};

int main(){

    string s1 = "123";
    string s2 = "23";
    Solution so;
    // cout<<so.plus("2460", "369")<<endl;
    // cout<<so.cheng('5', "123")<<endl;
    cout<<so.multiply(s1, s2)<<endl;


    return 0;
}