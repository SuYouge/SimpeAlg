#include <iostream>
#include <queue>

using namespace std;

/*
以n=7 m=9为例

0 1 2 3 4 5 6

r1 : 9%7 = 2 删除2的前一个

0 2 3 4 5 6
0 1 2 3 4 5

r2 : 9%6 = 3 删除3的前一个

0 1 3 4 5
0 1 2 3 4

r3 : 9%5 = 4 删除4的前一个

1 2 3 4
0 1 2 3

r4 : 9%4 = 1  删除1的前一个

1 2 3
0 1 2

r5 : 9%3 = 0 删除0的前一个

0 1
0 1

r6 : 9%2 = 1 删除1的前一个

1
0

*/


class Solution {
public:
    int lastRemaining(int n, int m) {
        // 队列
        queue<int> q;
        for(int i = 0;i<n;i++)
            q.push(i);
        int cnt = 1;
        while(q.size()>1){
            if(cnt % m== 0 && cnt!=0){
                // cout<<"pop "<<q.front()<<"cnt ="<<cnt<<endl;
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
            }
            cnt++;
        }
        return q.front();
    }
};

int main(){

    Solution so;
    cout<<so.lastRemaining(70866,116922);

    return 0;
}