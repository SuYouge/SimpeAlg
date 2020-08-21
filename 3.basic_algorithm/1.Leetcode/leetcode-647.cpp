#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
    dp[i][j]表示第i到第j之间的回文子串数目
    dp[0][0] = 1
    dp[i][i] = 1
    求dp[0][s.size()-1]
    状态转移：
    int tmp = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
    if(s[i]==s[j] && note[i+1][j-1]==1){
        dp[i][j] = tmp + 1;
        note[i][j] = 1;
    }
    else{
        dp[i][j] = tmp;
    }
*/
class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 1) return 1;
        vector<vector<int>> dp;
        vector<vector<int>> note;
        int size = s.size();
        for(int i = 0;i<size;i++){
            vector<int> tmp(size, 0);
            dp.push_back(tmp);
            note.push_back(tmp);
        }
        for(int i = 0;i<size;i++){
            dp[i][i] = 1;
            note[i][i] = 1;
            if(i>0&&(s[i]==s[i-1]))
                note[i][i-1] = 1;
        }

        // 开始填表
        for(int m = 1;m<size;m++){
            for(int n =0;n+m<size;n++){
                int i = n;
                int j = n+m;
                int tmp = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                if(s[i]==s[j] && note[i+1][j-1]==1){
                    dp[i][j] = tmp + 1;
                    note[i][j] = 1;
                }
                else{
                    dp[i][j] = tmp;
                }
            }
        }
        return dp[0][size-1];
    }
};
int main(){

    vector<string> input = {"fdsklf"};
    for(auto i:input){
        Solution so;
        cout<<so.countSubstrings(i);
    }

    return 0;
}