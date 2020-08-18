#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int remove(vector<int>& boxes){
        if(boxes.size() == 0) return 0;
        int res = 0;
        for(int i =0,j= i+1;i<boxes.size();i++){

            while(j<boxes.size() && boxes[i] == boxes[j])
                j++;
            cout<<"j = "<<j<<" i = "<<i<<endl;
            vector<int> newboxes(boxes.size() - (j-i));
            for(int k = 0,p=0;k<boxes.size();k++){
                if(k==i)
                    k = j;
                if(k<boxes.size())
                    newboxes[p++] = boxes[k];
            }
            res = max(res, remove(newboxes) + (j-i)*(j-i));
        }
        return res;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        return remove(boxes);
    }
};


int main(){

    Solution so;
    // vector<int> boxes = {1,3,2,2,2,3,4,3,1};
    vector<int> boxes = {1,2,3,4,5,6,7,8,9,10};
    cout<< so.removeBoxes(boxes);

    return 0;
}