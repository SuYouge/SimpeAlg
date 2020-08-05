#include <iostream>
#include <vector>
using namespace std;

class Solution{

    public:
        string longestCommonPrefix(vector<string>& strs){
            if(strs.empty()) return "";//如果容器vector 为空，则返回“”
            string res = strs[0];//选择第一个字符串作为对照标准

            for (int i=1;i<strs.size();i++){
                for (int j=0;j<res.length();j++){
                    if (res[j]==strs[i][j])
                        continue;
                    else
                    {
                        res.erase(j);//找到第一个不符合的字符位置，从pos=j处开始删除之结尾
                        break;                   
                    }
                
                }
                        
            }
        return res;
        }
};

int main(){
    vector<string> str{"ssd","ssf"};
    Solution solution;
    string ret = solution.longestCommonPrefix(str);
    cout<<ret<<endl;
    return 0;
}
