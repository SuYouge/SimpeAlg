#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {

private:
    unordered_set<string> deadset;

    unordered_set<string> convert(vector<string>& deadends){
        unordered_set<string> output;
        for(auto vi = deadends.begin(); vi!=deadends.end();vi++){
            output.insert(*vi);
        }
        return output;
    }

    bool indead(string s){
        return deadset.count(s)!=0;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        this->deadset = convert(deadends);
        unordered_set<string> dead;
        if(indead("0000")) return -1; // 
        queue<string> queue;
        queue.push("0000");
        int step = 0;
        while(!queue.empty()){
            int size = queue.size();
            while (size-->0)
            {
                string tmp = queue.front();
                // cout<<"tring with : "<<tmp<<endl;
                queue.pop();
                if(target==tmp) return step;
                for(int i =0;i<4;i++){
                    int num = tmp[i]-'0';
                    tmp[i] = (char) ('0'+(num+9)%10); // 数字+1
                    if(!indead(tmp)){
                        queue.push(tmp);
                        deadset.insert(tmp);
                    }
                    tmp[i] = (char) ('0'+(num+11)%10); // 数字+1
                    if(!indead(tmp)){
                        queue.push(tmp);
                        deadset.insert(tmp);
                    }
                    tmp[i] = (char) ('0'+num); // 复原当前位
                }
            }
            step++;
        }
        return -1;
    }
};


int main(){
    vector<string> deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target = "8888";
    Solution so;
    cout<<so.openLock(deadends, target)<<endl;
    return 0;
}