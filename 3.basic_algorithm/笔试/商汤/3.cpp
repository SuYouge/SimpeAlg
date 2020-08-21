#include<bits/stdc++.h>
using namespace std;
/*
找最长上升路径，遍历+dfs
*/
int m , n;
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
/*
3 3 
9 1 4
6 2 8
5 5 7
*/


vector<pair<int,int>> find_neighbor(vector<vector<int>>& imap,pair<int,int>& target){
    vector<pair<int,int>> res;
    for(auto d:dir){
        int y = target.first + d.first;
        int x = target.second + d.second;
        if((y>=0&&y<m )&&(x>=0&&x<n)){
            // cout<<"finding "<<y<<" "<<x<<endl;
            if((imap[y][x]>imap[target.first][target.second])){
            res.push_back({y,x});
            }
        }
    }
    return res;
}

int max_length = 0;
void dfs(vector<vector<int>>& imap, vector<pair<int,int>>& path, pair<int,int> start){
    path.push_back(start);
    max_length = max_length<path.size()? path.size():max_length;
    auto neighbor = find_neighbor(imap, start);
    if(neighbor.size()==0){ path.pop_back(); return;}
    for(auto n:neighbor){
        dfs(imap, path, n);
    }
    path.pop_back();

}



int main(){


    cin>>m>>n;
    if(m==0||n==0){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>> imap;
    // map<int,pair<int,int>> list;
    for(int i = 0;i<m;i++){
        vector<int > tmp(n);
        // visited.emplace_back(tmp);
        for(int j = 0;j<n;j++){
            int in;
            cin>>in;
            tmp[j] = in;
            // list.insert({in,{i,j}});
        }
        imap.emplace_back(tmp);
    }

    for(int i = 0;i<m;i++){
        for(int j =0;j<n;j++){
            // for(auto c: visited) c.clear();
            vector<pair<int,int>> path;
            pair<int,int> start = {i,j};
            dfs(imap, path, start);
        }
    }
    

    cout<<max_length<<endl;

    return 0;
}