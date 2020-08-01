#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {

public:
    vector<int> square(int n){
        vector<int> output;
        int sq;
        for(int i=1;i*i<=n;i++){
            sq = i*i;
            output.push_back(sq);
        }
        // for(int i=0;i<output.size();i++){
        //     cout<<output[i]<<" ";
        // }
        return output;
    }

public:
    int numSquares(int n) {
        auto sq = square(n);
        vector<bool> used(n+1);
        queue<int> queue;
        /**/
        int step = 0;
        queue.push(n);
        used[n] = true;
        /**/
        while(!queue.empty()){
            int size = queue.size();
            step ++;
            while(size--){
                int curr = queue.front();
                queue.pop();
                for(int num : sq){ // 不能反向遍历
                    int next = curr - num;
                    if(next<0) break;
                    if(next == 0) return step;
                    if(used[next]) continue;
                    used[next] = true;
                    queue.push(next);
                }
            }
        }
        return n;
    }
};


int main(){

    int n = 12;

    Solution so;
    cout<<so.numSquares(n);

    return 0;
}