#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string read(string input){
    // if(input=="1") return "11";
    char tmp = input[0];
    // cout<<tmp<<endl;
    int cnt(0);
    vector<pair<int,char>> m;
    // cout<<" input length ="<<input.length()<<endl;
    for(int i=0;i<input.length();i++){
        if(tmp == input[i]){
            // cout<<"tmp = "<<tmp<<" input["<<i<<"] = "<<input[i]<<endl;
            cnt++;
            // if(i==input.length()-1){
            //     m.push_back(make_pair(cnt, tmp));
            // }
        }else{
            m.push_back(make_pair(cnt, tmp));
            // cout<<cnt<<" 个 "<<tmp<<endl;
            // cout<<"change from"<<tmp<<" to "<<input[i]<<endl;
            tmp = input[i];
            cnt = 1;
        }
    }
    m.push_back(make_pair(cnt, tmp));
    string output;
    for(int i=0;i<m.size();i++){ // n个m n个m
        output = output + to_string(m[i].first)+ m[i].second;
    }
    // cout<<output;
    return output;
}
string describe(int n){
    if(n==1) return "1";
    return read(describe(n-1));
}

class Solution {
public:
    string countAndSay(int n) {
        return describe(n);
    }
};


int main(){

    int n = 31;
    Solution so;
    cout<<so.countAndSay(n)<<endl;
    // cout<<read("1211")<<endl;
    return 0;
}
