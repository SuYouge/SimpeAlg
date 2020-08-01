#include <vector>
#include <iostream>

using namespace std;

/*
注意细节 各个位置的等号
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
    if (nums.size()<= 0) {
        return -1;
    }
    auto s = nums;
    auto t= target;
    int head = 0; 
    int tail = nums.size()-1;
    int mid = 0;
    while(head<=tail){
        mid = (head+tail)/2;
        if(s[mid]==t) return mid;
        else if ((s[mid]>=s[head]&&(t>=s[head]&&t<=s[mid]))||(s[mid]<s[head]&&(t<=s[mid]||t>s[tail]))) tail = mid-1;
        else head = mid+1;
        }
    return -1;
    }
};


int main(){

    vector<int> s = {4,5,6,7,0,1,2};
    int target = 2;
    Solution so;
    cout<<so.search(s,target);
    return 0;
}