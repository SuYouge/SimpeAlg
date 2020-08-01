#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

/*有奇怪bug*/
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        int div = numRows!=1? numRows-1 : 1; // 前面是正常的分母 后面是1行时用的分母
        int v_num = len/(div+ numRows-1); // v型数量，防止除0
        cout<<v_num<<endl;
        int res = len - v_num * (div+ numRows-1);//剩余字符数目
        cout<<res<<endl;
        int column = res > numRows ? (v_num * (numRows-1) + res-numRows+1 + (int)(v_num==0)) //在不足1个v的时候添加1列，因为v_num=0
                : (v_num * div + (int)(res!=0));
        cout<<column<<endl;
        string tmp;
        if(column!=0){
        char matrix[numRows][column];
        int t = 0;
        for(int j=0;j<column;j++){
            for(int i=0;i<numRows;i++){
                // 首先判断是不是在v字第一笔
                if(j%(div)==0 && t!= len){
                    matrix[i][j] = s[t];
                    t++;
                }else if(j%(div) == (div -i)&& t!= len){//判断是否在斜线上,保证还有剩余的字符
                    matrix[i][j] = s[t];
                    t++;
                }else{
                    matrix[i][j] = '*';
                }
            }
        }
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<column;j++){
                cout<<matrix[i][j]<<" ";
                if(matrix[i][j]!='*')
                tmp += matrix[i][j];
            }
            cout<<endl;
        }
        }
                
        return tmp;
    }
};
/*
"PAYPALISHIRING"
5
*/

int main(){

    string s = "PAYPALISHIRING";
    int rows = 5;
    Solution sol;
    cout<<sol.convert(s,rows);
    return 0;
}