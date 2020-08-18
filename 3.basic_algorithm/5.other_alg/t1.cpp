#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3) return false;
        int cnt = 0;
        for(auto v:arr){
            if(v%2==1&&cnt==0){
                cnt++;
            }else if(v%2==1 &&cnt>0){
                cnt++;
                if(cnt==3){
                    return true;
                }
            }else if(v%2==0){
                cnt = 0;
            }
        }
        return false;
    }
};

int main(){

    vector<int> arr = {1,1,1,1,1};
    Solution so;

    cout<<so.threeConsecutiveOdds(arr)<<endl;

    return 0;
}