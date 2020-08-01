#include <iostream>
#include <algorithm>

using namespace std;

int n,m,c1,c2;

int e[510][510],weight[510],dis[510],num[510],w[510];

bool visit[510];

const int inf = 99999999;

int main(){

    // n为节点数目[0-n-1]， m为边数目，c1为起点，c2为终点
    scanf("%d%d%d%d", &n,&m,&c1,&c2);
    for(int i=0; i<n;i++){
        scanf("%d",&weight[i]); // 读取每个结点的权重，即每个城镇上的救援队数目
    }

    fill(e[0],e[0]+510*510,inf); // fill 属于stl，填充容器, 邻接矩阵赋初值
    fill(dis,dis+510,inf); // dijk维护的最短距离数组

    int a,b,c;

    // 填充邻接矩阵
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[a][b] = e[b][a] = c;
        // printf("%d to %d = %d \n", a,b,c);
    }
    
    /* 初始化 dijkstra */

    dis[c1] = 0; // 设定dijk的起点
    w[c1] = weight[c1]; // 累积的点权，即救援队数目
    num[c1] = 1; // 到i最短路径的条数

    /* dijkstra */

    // 外层循环 遍历所有结点
    for(int i=0;i < n;i++){
        int u =-1; auto minn = inf;
        // 内层循环 找到当前dis[]中没有访问过的最小值
        for(int j=0;j<n;j++){
        if(visit[j]==false && dis[j]<minn){
                u = j;
                minn = dis[j];
            }
        }
        // printf("shortest path : c1 to %d = %d \n",u,minn);
        if(u==-1) {break;} // 没有找到这样的点，那么遍历结束

        visit[u] = true; // 更新访问状态

        for(int v=0;v < n;v++){
            if(visit[v] == false && e[u][v]!= inf){ // 未访问过且与u连通的点
                if(dis[u] + e[u][v] < dis[v]){ // 新连通的点是否让之前的路径变短了呢
                    dis[v] = dis[u] +e[u][v]; // 更新最短距离
                    num[v] = num[u]; // 新的u使得起点到v的距离变短， 那么到u的最短路径数目就是到v的最短路径数目
                    w[v] = w[u] + weight[v]; // 更新当前v结点上累积的权重值
                }else if(dis[u] + e[u][v] == dis[v]){  // 没有更短，但是有可能让累积权重变大
                // 如果新的u没有使得起点到v的距离变短， 而是维持相等那么就应将u的最短路径数目加入v的最短路径数目中
                    num[v] = num[v]+ num[u] ;
                    if(w[u]+weight[v]>w[v])
                        w[v] = w[u]+weight[v]; // 更新
                }
            } 
        }
    }
    // printf("shortest path to %d = %d \n",c2 ,dis[c2]);
    printf("%d %d",num[c2],w[c2]);
    return 0;
}