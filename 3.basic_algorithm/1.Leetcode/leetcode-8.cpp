#include <iostream>
#include <string>
#include <climits>
using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        // 消除前导空格
        while(*str.begin()==' ') str.erase(str.begin());
        int ans = 0;

        // 判断正负号
        bool flag = false;
        int i =0;
        if(str[i]=='-') {flag = true; i++;}
        else if(str[i]=='+') {i++;}
        while(str[i]>='0'&&str[i]<='9'){
            int tail = str[i] -'0';
            if(flag == false && ( ans>INT_MAX/10 || (ans==INT_MAX/10 && tail >7)   )) {
                return INT_MAX;
            } 
            if(flag == true && ( -ans<INT_MIN/10 || (-ans==INT_MIN/10 && tail >8 ))){
                return INT_MIN;
            }
            ans  =  ans*10 + tail;
            i++;
        }
        if(flag) ans = -ans;
        
        return ans;
    }
};

int main(){

    string s = " -42";

    Solution so;
    cout<< so.myAtoi(s);

    return 0;
}