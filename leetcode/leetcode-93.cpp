#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

class Solution {

private:
    string s;
    vector<vector<string>> res;
    vector<string> path;

private:
    string getstring(int start, int n){
        return s.substr(start,n);
    }

    bool valid(int start, int n){
        // cout<<"start : "<<start<<" n: "<<n<<endl;
        // cout<<s.substr(start,n)<<endl;
        if(s[start]=='0'&&n!=1) return false; // "0000"
        if(start==s.size()) return false;
        return stoi(s.substr(start,n))<=255;
    }

private:
    bool dfs(int start, int n){ // 4
        // cout<<"start, n : "<<start<<"  "<<n<<endl;
        // cout<<s.size();
        if(s.size()-start>3*n)  {
            // cout<<"break for left to long"<<endl;
            return  false;} // 初始状态s.size-0=11
        if(start==s.size()&&path.size()==4) { // "1111"
            // cout<<"imhere"<<endl;
            res.push_back(path); return true;
        } // 成功返回一个结果
        // cout<<"imhere"<<endl;
        bool ret = false; //否则开始分支
        for(int i=1;i<=3;i++){
            if(valid(start,i)){ // 判断起点开始的n位是否合法
                // cout<<"insert : "<<s.substr(start,i)<<endl;
                path.push_back(getstring(start,i)); // 如果合法插入路径
                ret = dfs(start+i,n-1); // 要全部结果所以每一个push值都要弹出
                path.pop_back();
                // cout<<"pop : "<<s.substr(start,i)<<endl;
                
            }
        }
        return ret;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        dfs(0,4);
        vector<string> output;
        for(int i=0;i<res.size();i++){
            string tmp;
            for(int j=0;j<res[i].size();j++){
                tmp = tmp + res[i][j];
                if(j!=res[i].size()-1) tmp+="." ;
            }
            cout<<tmp<<endl;
            output.push_back(tmp);
        }
        return output;
    }
};


int main(){
    string s = "1111"; // "0000"
    Solution so;
    so.restoreIpAddresses(s);


    return 0;
}