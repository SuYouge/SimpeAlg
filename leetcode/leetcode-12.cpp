/*
整数转罗马数字
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        vector<int> roma = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> list = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        while(num!=0){
            while(*roma.rbegin()!=1){
                if(*roma.rbegin()>num) roma.pop_back();
                if(*roma.rbegin()<=num) break;
            }
            // cout<<roma.size()<<endl;
            s=s+list[roma.size()-1];
            // cout<< *roma.rbegin()<<endl;
            num = num - *roma.rbegin();
        }
        return s;
    }
};


int main(){
    int r = 1994;
    Solution so;
    cout<<so.intToRoman(r);
    return 0;
}