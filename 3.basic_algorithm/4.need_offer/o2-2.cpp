#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row=board.size();     //行
        col=board[0].size();  //列
        len=word.size();
        int index=0;  //word的下标
        vector<vector<int>> flag(row,vector<int>(col,0));//初始化0表示未被访问，用1表示被访问过

        //board1.assign(board.begin(),board.end());
        //word1.assign(word.begin(),word.end());
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(board[i][j]==word[index]) {
                    bool temp=recursion(i,j,index,flag,board,word);
                    if(temp==true) return temp;
                }
            }
        }
        return false;
    }
    bool recursion(int i,int j,int index,vector<vector<int>> &flag,vector<vector<char>>& board,string &word) {//flag这里是引用，表示四个递归分支共享一个flag
        if(i<0||i>row-1||j<0||j>col-1) {  //数组越界
            return false;
        }else if(board[i][j]==word[index]&&flag[i][j]==0) {//如果匹配且未被访问
            if(index==len-1) //是否匹配到最后一个字符
                return true;
            else {
                flag[i][j]=1;  //标记访问过             
                if((recursion(i+1,j,index+1,flag,board,word)||recursion(i-1,j,index+1,flag,board,word)||recursion(i,j+1,index+1,flag,board,word)||recursion(i,j-1,index+1,flag,board,word))==false) { //回溯
                    flag[i][j]=0;
                    return false;
                }else 
                    return true;
            }
        }else {
            return false;
        }

    }
private:
    int row,col;
    int len;      //word的长度  
};

int main() {
    vector<vector<char>> board = {
        {'a', 'a', 'c', 'e'}, 
        {'s', 'f', 'c', 's'}, 
        {'a', 'd', 'e', 'e'}};
    string word = "asa";
    Solution so;
    cout << so.exist(board, word);

    return 0;
}