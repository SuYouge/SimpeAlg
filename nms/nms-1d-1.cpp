/*
 * @Author: Yogurt Suee
 * @Date: 2020-02-20 22:23:20
 * @LastEditors: Yogurt Suee
 * @LastEditTime: 2020-02-20 22:58:31
 * @Description: 优化版1Dnms-算法1
 */


/*
输入：3,4,7,6,7,1,2,2
输出：
max value = 7  at  3
max value = 7  at  5
max value = 2  at  8
*/

/*
输入：1 ，2 ，3 ，4 ，5 ，4 ，3 ，1 ，9 ，7 ，5 ，3 ，4  
max value = 5  at  5
max value = 9  at  9
max value = 4  at  13
*/

#include <vector>
#include <iostream>

using namespace std;

void algorithm_1(const vector<int> a){
    int W = a.size();
    int i =1 ;
    vector<int> max;
    while(i+1<W){
        if (a[i]>a[i+1])
        {
            if(a[i]>=a[i-1]){
                max.push_back(i);
            }
        }else{
            i = i + 1;
            while((i + 1 < W)&& (a[i]<=a[i+1])){
                i = i + 1;
            }
            if (i + 1 < W){
                max.push_back(i);
            }
        }
            i = i + 2;
    }
    for(auto it = max.begin();it!=max.end();it++){
        cout<<"max value = "<<a[*it]<<"  at  "<<*it<<endl;
    }
}

int main(){
    int n = 15; // n大于2
    int tmp;
    cout<<"input sequence to nms"<<endl;
    vector<int> input;
    for(int i;i<n;i++){ // 输入向量中共有n个元素，首尾两个元素都是0用来padding，W=n，即当i=n-1时刚好到达序列的边界
        if(i==0 || i==n-1){
            tmp = 0;
        }else{
            cin>>tmp;
        }
        input.push_back(tmp);
    }
    for(auto it = input.begin();it!=input.end();it++){
        cout<<*it<<"  ";
    }
    cout<<endl;
    algorithm_1(input);
    return 0;
}

