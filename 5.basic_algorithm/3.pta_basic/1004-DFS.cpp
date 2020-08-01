#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100]; // 非叶子结点用向量表示，每个向量中存放若干叶子结点后代

int book[100], maxdepth = -1; // 每层的叶子结点数目行程一个数组

// dfs过程
void dfs(int index, int depth){
    if(v[index].size()==0){ // 2. 直到没有后代
        book[depth]++; // 在这一层中记录
        maxdepth = max(maxdepth, depth); //更新最大深度
        return ; // 跳出递归，返回上一层
    }
    for(int i=0; i< v[index].size();i++){
        dfs(v[index][i],depth+1); // 1. 进入最深处
    }
}


int main(){

    /* 读取一棵树 */

    int n,m,k,node,c;

    scanf("%d %d",&n,&m); // n为总结点数目 m为非叶子结点数目

    for(int i=0;i<m;i++){
        scanf("%d %d",&node,&k); // 非叶子结点id以及它的后代数目
        for(int j=0; j< k;j++){
            scanf("%d",&c);
            v[node].push_back(c); // 非叶子节点构成一个数组，每个数组中存放后代id
        }
    }

    dfs(1,0); // 深度优先遍历, 01是根节点
    printf("%d",book[0]);
    for(int i=1; i<= maxdepth; i++){
        printf(" %d",book[i]);
    }

    return 0;
}