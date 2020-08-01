#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
根据匹配规则p生成有限状态机
https://leetcode-cn.com/problems/regular-expression-matching/solution/yi-bu-dao-wei-zhi-jie-an-zheng-ze-biao-da-shi-de-s/
https://blog.csdn.net/little_nai/article/details/52541210
条件有2： 需要为后缀表达式形式的正则； 需要写明操作符。

*/

class Solution {
public:

    vector<bool>  dfs(vector<vector<bool>>& graph, vector<bool>& mark);
    vector<bool>  dfs(vector<vector<bool>>& graph, int s);
    void dodfs(vector<vector<bool>>& graph, vector<bool>& mark, int v);
    bool isMatch(string s, string p) {
        auto sc = s;
        auto pc = p;

        int m = pc.length()+1;

        vector<vector<bool>> graph(m, vector<bool>(m, false));
        
        for(int i =0;i<m-1; i++){
            if(pc[i]=='*'){
                graph[i-1][i] = true;
                graph[i][i-1] = true;
                graph[i][i+1] = true;
            }else if(pc[i]==')'){
                graph[i][i+1] = true;
            }
        }

        vector<bool> mark = dfs(graph, 0);

        for(int i=0; i<sc.length();i++){
            vector<bool> match(m, false);
            for(int j=0; j<m;j++){
                if(mark[j]){
                    if(j==m -1){
                        continue;
                    }
                    if(pc[j]==sc[i]|| pc[j]=='.'){
                        match[j+1] = true;
                    }
                }
            }
            mark = dfs(graph,match);
        }
        return mark[m-1];
    }
};

vector<bool>  Solution::dfs(vector<vector<bool>>& graph, int s){
    vector<bool> re(graph.size(), false);
    dodfs(graph,re,s);
    return re;
}

vector<bool>  Solution::dfs(vector<vector<bool>>& graph, vector<bool>& mark){
    vector<bool> re(graph.size(), false);
    for(int i=0; i<mark.size();i++){
        if(mark[i]){
            dodfs(graph,re,i);
        }
    }
    return re;
}

void Solution::dodfs(vector<vector<bool>>& graph, vector<bool>& mark, int v){
    mark[v] = true;
    for(int i=0;i<graph.size();i++){
        if(!mark[i] && graph[v][i]){
            dodfs(graph,mark,i);
        }
    }
}

int main(){

    string s = "mississippi";
    string p = "mis*is*p*.";

    Solution so;

    cout<<so.isMatch(s,p);


    return 0;
}