#include <iostream>
#include <vector>
#include <algorithm>
/*
死在超时
*/
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int column = height.size(); 
        if(column==0) return 0;
        int rows = *max_element(height.begin(),height.end());
        // cout<<rows<<endl;
        int cnt(0);
        // vector< vector<int>> matrix;
        for(int i=0; i< rows;i++){
            // vector<int> tmp;
            vector<int> index;
            int tmp_cnt(0);
            for(int j=0;j<column;j++){
                if(i<height[j]){
                    // tmp.push_back(1);
                    index.push_back(j);
                    // cout<<j<<" ";
                    if(index.size()>1){
                    tmp_cnt+=(*(index.end()-1)-*(index.end()-2)-1);
                }
                }else{
                    // tmp.push_back(0);
                }
            }
            cnt+=tmp_cnt;
            // matrix.push_back(tmp);
        }
        return cnt;
        
    }
};

int main(){

    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution so;
    cout<<so.trap(input)<<endl;

    return 0;
}