#include <iostream>
#include <vector>
using namespace std;

class binarysearch{
public:
    // int search(vector<int>& input, int target){
    //     int left = 0, right = input.size();
    //     int mid;
    //     while(left<right){ // left == right时退出
    //         // mid = (left + right)/2;
    //         mid = left + (right-left)/2;
    //         // mid = left + right>>1;
    //         if(input[mid]<target){
    //             // right = mid; // target在mid左边
    //             left = mid + 1;
    //         }else{
    //             // left = mid+1; // target在mid右边
    //             right = mid;
    //         }
    //     }
    //     // cout<<"exit at "<<left<<" "<<right<<endl;
    //     return left;
    // }
    int search(vector<int>& input, int target){
        // [left, mid-1] [mid,right]
        int left = 0, right = input.size();
        int mid;
        while(left<right){ // left == right时退出
            // mid = (left + right)/2;
            mid = (left + right + 1)/2;
            // mid = left + right>>1;
            if(input[mid]<target){
                // right = mid; // target在mid左边
                left = mid;
            }else{
                // left = mid+1; // target在mid右边
                right = mid - 1;
            }
        }
        cout<<"exit at "<<left<<" "<<right<<endl;
        return left;
    }
    
    int bsearch(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0] == target ? 1 : 0;
        int left= 0,right = nums.size();
        int mid;
        // [left, mid] [mid+1,right]
        while(left<right){
            mid = left + (right - left)/2;
            if(nums[mid]>=target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        if(nums[left]!=target) return 0;
        int res = left;
        // cout<<left<<endl;
        right = nums.size();
        // [left,mid-1] [mid, right]
        while(left<right){
            mid = (left + right + 1)/2;
            if(nums[mid]<=target){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        return left - res + 1;
    }

};


int main(){


    vector<int> v = {2,2};
    int target = 2;
    binarysearch b;
    cout<< b.bsearch(v, target);
    return 0;
}