#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
        string convert(string s , int numRows){
        if (numRows==1) return s;
        std::vector<string> rows(min(numRows,int(s.size())));
        int curRow =0;
        bool goingDown = false;
        for (char c:s){
            rows[curRow]+=c;
            if (curRow==0||curRow ==numRows-1){
                goingDown =!goingDown;           
            }
            curRow += goingDown ? 1:-1;
        }
        string ret;
        for (string row : rows){
            ret += row;
        }
        return ret;
        }
};
int main(){
string str = "LEETCODEISHIRING";
Solution solution;
string ret = solution.convert(str,4);
cout<<ret<<"\n"<<endl;
return 0;
}

