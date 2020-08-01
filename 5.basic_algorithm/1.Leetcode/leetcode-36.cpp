#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/*
hashtable:
9*27
0-8 表示在第i行有这个值
9-17 表示在第j列有这个值
18-26 表示第第k个方格中有这个值
*/



class Solution {

public:
    int kthblock(int i, int j){
        int row = i/3;
        int col = j/3;
        return row*3+col;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> hash;
        for(int i =0;i<9;i++){
            vector<int> tmp(27);
            hash.push_back(tmp);
        }
        for(int i=0;i<rows;i++){
            for(int j=0; j<cols;j++){
                int k = kthblock(i, j);
                if(board[i][j]!='.'){
                    int tmp = board[i][j]-'0';
                    // cout<<tmp<<"in "<<i<<" row "<<j<<" col "<<k<<" block"<<endl;
                    if(hash[tmp-1][i]>0||hash[tmp-1][9+j]>0||hash[tmp-1][18+k]>0) {
                        // cout<<" i = "<<hash[tmp-1][i]<<" "<<endl;
                        // cout<<" j = "<<hash[tmp-1][9+j]<<" "<<endl;
                        // cout<<" k = "<<hash[tmp-1][18+k]<<" "<<endl;
                        return false;}
                    hash[tmp-1][i]++;
                    hash[tmp-1][9+j]++;
                    hash[tmp-1][18+k]++;
                }
            }
        }
        return true;
    }
};

int main(){

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution so;
    so.isValidSudoku(board);

    return 0;
}