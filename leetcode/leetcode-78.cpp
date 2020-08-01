#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

private:

    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;

public:
    void dfs(int n, int start){
    if(path.size()==n){
        cout<<"n = "<<n<<endl;
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        res.push_back(path);
    }
    for(int i = start;i<candidates.size();i++){
        path.push_back(candidates[i]);
        dfs(n+1,i+1);
        path.pop_back();
    }
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        this->candidates = nums;
        dfs(0,0);
        return res;
    }
};

int main(){

    vector<int> input = {1,2,3};

    Solution so;

    so.subsets(input);


    return 0;
}