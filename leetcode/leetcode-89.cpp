#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

class Solution {

private:
    vector<int> res;
    int n;

void dfs(string s, int i){
    if(s.size()==n){
        cout<<stoi(s,0,2)<<" ";
        res.push_back(stoi(s,0,2));
    }
    else if(i==0) {
        cout<<"insert 0"<<endl;
        dfs(s+"0",0);
        cout<<"pop 0"<<endl;
        cout<<"insert 1"<<endl;
        dfs(s+"1",1);
        cout<<"pop 1"<<endl;
    }
    else if(i==1){
        cout<<"insert 1"<<endl;
        dfs(s+"1",0);
        cout<<"pop 1"<<endl;
        cout<<"insert 0"<<endl;
        dfs(s+"0",1);
        cout<<"pop 0"<<endl;
    }
}


public:
    vector<int> grayCode(int n) {
        if(n==0) return {0};
        this->n=n;
        dfs("", 0);
        return res;
    }
};

int main(){

    int n = 3;
    Solution so;
    so.grayCode(n);

    return 0;
}