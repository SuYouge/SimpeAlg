#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {

private:
    vector<vector<string>> res;
    vector<string> board;
    int rm;

public:
    bool isvalid(int row,int col){
        for(int i=0;i<row;i++){ // 检查列
            if(board[i][col]=='Q')
             return false;
        }
        for(int i=row-1,j=col-1; i>=0&&j>=0; i--,j--){ // 左上
            if(board[i][j]=='Q')
             return false;
        }

        for(int i=row-1,j=col+1;j<rm&&i>=0;i--,j++){ // 右上
            if(board[i][j]=='Q')
             return false;
        }
        return true;
    }


public:

    void dfs(int row){
        if(row==rm){
            for(int i=0;i<rm;i++){
                cout<<board[i]<<endl;
            }
            cout<<endl;
            res.push_back(board);
        }
        for(int i=0;i<rm;i++){
            if(!isvalid(row,i)) continue;
            board[row][i] = 'Q';
            dfs(row+1);
            board[row][i] = '.';        
        }
    }


public:
    vector<vector<string>> solveNQueens(int n) {
        this->rm = n;
        vector<string> init(n, string(n, '.'));
        board = init;
        for(int i=0;i<rm;i++){
            cout<<board[i]<<endl;
        }
        dfs(0);
        return res;
    }
};

int main(){

    int n =4;
    Solution so;

    cout<<so.solveNQueens(n).size();

    return 0;
}