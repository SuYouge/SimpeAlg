#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0) return "";
    if(strs.size()==1) return strs[0];
    
    /*升序排列*/
    std::sort(strs.begin(),strs.end()
        ,[](string a, string b ) {return a.size() < b.size();});
    if(strs[0].size()==0) return "";
    // for(auto vi = strs.begin();vi!= strs.end();vi++){
    //     cout<<*vi<<endl;
    // }
    int start = 0;
    while(start<=strs[0].size()-1){
        // cout<<start<<endl;
        int flag = false;
        for(int i=1;i<strs.size();i++){
            if(strs[i][start]==strs[0][start]){
                // cout<<strs[i][start]<<" == "<<strs[0][start]<<endl;
                flag = true;
            }else{
                flag = false;
                break;
            }
        }
        if(flag == true) start++;
        if(flag == false) break;
    }
    return strs[0].substr(0,start);
    }    
};


int main(){

    vector<string> s = {"",""};
    Solution so;
    cout<<so.longestCommonPrefix(s);

    return 0;
}