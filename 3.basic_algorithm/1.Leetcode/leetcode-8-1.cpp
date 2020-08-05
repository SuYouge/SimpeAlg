#include <iostream>
#include <limits.h>
using namespace std;
class Solution{
    public:
        int myAtoi(string str){
        int res = 0;
        int i = 0;
        int flag = 1;
        //check space
        while (str[i] == ' ') {i++;}
        //check sigma
        if (str[i] == '-') {flag =-1;}
        if (str[i] == '+'|| str[i]== '-') {i++;}
        //get number
        while(i<str.size()&&isdigit(str[i])){
            int r = str[i] - '0';
            //overflow problem
            if (res> INT_MAX/10||(res==INT_MAX/10&&r>7)){
                return flag>0 ? INT_MAX:INT_MIN;
            }
            res = res * 10+r;
            i++;
        }
        return flag>0?res:-res;
        
        }
};

int main(){
    string str = "123lk424";
    Solution solution;
    int ret = solution.myAtoi(str);
    cout<<ret<<endl;
    return 0;
}
