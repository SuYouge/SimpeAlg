#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

private: 
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(vector<int> candidates){
    if(candidates.size()==0){
        for(int i =0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        res.push_back(path);
    }
    for(int i=0;i<candidates.size();i++){
    	path.push_back(candidates[i]);
        vector<int>  tmp;
        tmp.assign(candidates.begin(),candidates.end());
        tmp.erase(tmp.begin()+i);
    	DFS(tmp);
        path.pop_back();
    }   
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        DFS(nums);
        return res;
    }
};

int main(){

    vector<int> input = {3,2,1};

    Solution so;

    so.permute(input);

    return 0;
}
