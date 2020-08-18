#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
/*
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5
*/
vector<pair<int,int>> list;
int main(){
    int m, n; // 学生数目和查询数目
    cin>>m>>n;
    list.resize(m);
    // printf("list size =%d\n", list.size());
    int socre_tmp;
    for(int i = 0;i<m;i++){
        cin>>socre_tmp;
        // printf("\nid = %d, score = %d\n", i+1, socre_tmp);
        list[i] = {i+1, socre_tmp};
        // list.push_back({i+1, socre_tmp});
    }
    char type;
    int op1,op2;
    for(int i = 0;i<n;i++){
        cin>>type>>op1>>op2;
        // printf("\ntype = %c A = %d B = %d\n", type, op1, op2);
        if(type == 'Q'){ // 查询op1到op2的人数
            if(op1>op2){
                int tmp = op2;
                op2 = op1;
                op1 = tmp;
            }
            int max = -1;
            // printf("from %d to %d \n", op1-1,op2-1);
            for(int i = op1 - 1;i <op2;i++){
                if(max<list[i].second)
                    max = list[i].second;
            }
            // cout<<endl;
            cout<<max<<endl;
        }else if(type=='U'){ // 将编号为op1的同学成绩修改为op2
            if(list[op1-1].second!=op2)
                list[op1-1].second = op2;
        }
    }
    return 0;
}