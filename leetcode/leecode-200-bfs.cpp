#include <iostream>
#include <vector>
#include <queue>
// #include <unordered_set>
#include <set>
using namespace std;

class Solution {
private:
    int rows;
    int cols;
    int count = 0;
    int x= 0,y= 0,xx=0,yy=0;
public:
    int numIslands(vector<vector<char>>& grid) {
        this->rows=grid.size();
        this->cols=rows>0?grid[0].size():0;
        vector<pair<int,int>> delta = {{-1,0},{0,1},{1,0},{0,-1}}; // 下，右，上，左
        if(rows==0||cols==0) return 0;
        queue<pair<int,int>> queue;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    queue.push({i,j});
                    grid[i][j]='0';
                    while(!queue.empty()){
                        x = queue.front().first;
                        y = queue.front().second;
                        queue.pop();
                        for(int k =0;k<4;k++){
                            xx = x + delta[k].first;
                            yy = y + delta[k].second;
                            if(xx<0||xx>=rows||yy<0||yy>=cols) continue;
                            if(grid[xx][yy]=='1'){
                                grid[xx][yy]='0';
                                queue.push({xx,yy});
                            }
                        }
                    }
                    count++;
                }
        }
        return count;
    }
};

int main(){

    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};
    Solution so;
    cout<<so.numIslands(grid);

    return 0;
}