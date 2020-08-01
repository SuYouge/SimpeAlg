/* Directed Graph */
/* Undirected Graph*/
/* C style */

/*c1 c2 L*/
/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define INF  (0x6fffffff)

const int MaxVertexNum = 501;

typedef int WeightType ; // 才发现顺序和#define 是相反的
typedef int DataType ;
typedef int Vertex;
int DFS(int* pre, int begin, int v);
/* adj matrix */

/* Graph datastructure */
typedef struct GNode* PtrToGNode;
struct GNode{
    int Nv; // 顶点数
    int Ne; // 边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph; // instance

/* Edge datastructure */
typedef struct ENode* PtrToEdge;
struct ENode
{   
    Vertex V1, V2; // directed
    WeightType Weight;
};
typedef PtrToEdge Edge; // instance

/* Graph init Process */

/* Step 1, Created a graph with vertex but no edge */

MGraph CreateGraph(int VertexNum){

    Vertex V,W;
    MGraph Graph; // declare

    Graph = (MGraph)malloc(sizeof(struct GNode)); // this line is important
    Graph ->Nv = VertexNum;
    Graph ->Ne = 0;

    /* allocate init value for matrix */
    for(V =0; V<Graph->Nv; V++){
        for(W =0; W<Graph->Nv; W++){
            Graph->G[V][W] = INF; // set inf for directed
        }
    }
    return Graph;
}

/* Step 2, insert one edge with vertex */
void InsertEdge(MGraph Graph, Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight; // for undirected graph
}

MGraph BuildGraph(int v_Cities, int e_Roads){
    MGraph Graph; //
    Edge E; // temp Edge
    int Nv, i; 
    Nv = v_Cities;

    /* 1. get vertex num */
    // scanf("%d",&Nv);
    Graph = CreateGraph(Nv); // Graph is init by Nv

    /* 2. get edge num */
    Graph->Ne = e_Roads;
    // scanf("%d", &(Graph->Ne));

    for(int V=0; V<Graph->Nv; V++){
        scanf("%d", &(Graph->Data[V]));
        printf("%d ", Graph->Data[V]);
    }
    printf("\n");

    if(Graph->Ne!=0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0; i<Graph->Ne;i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            printf("%d th, begin: %d, end: %d, weight: %d \n", i, E->V1, E->V2,E->Weight);
            InsertEdge(Graph, E);
        }
    }
    return Graph; // 不写返回值竟然不会报错
}
int DFS(int* pre, int begin, int v){
    if(v==begin){
        printf("%d\n", begin);
        return begin;
    }
    DFS(pre, begin, pre[v]);
    printf("%d\n",v);
}
/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/
void Dijkstra(MGraph Graph, Vertex begin, Vertex end){
    WeightType d[MaxVertexNum];
    Vertex vis[MaxVertexNum];
    Vertex pre[MaxVertexNum];
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    int Nv = Graph->Nv;
    for(Vertex i=0 ;i<Nv; i++) {d[i] = (i==begin)? 0: INF;}
    for(Vertex i=0; i<Nv ;i++){
        printf("\n");
        for(Vertex i=0;i<Nv;i++) {printf("step %d: %d ", i, d[i]);}
        int u =-1; WeightType MIN = INF;
        for(Vertex j=0; j<Nv ;j++){
            if(vis[j] == 0 && d[j] <MIN){ //条件1 ： 未访问的最小值
                u = j;
                MIN = d[j];
            }
        }
        // 如果找不到小于INF的d[u]，说明剩下的顶点和起点不连通
        if(u==-1) return;
        vis[u] = 1;
        for(Vertex v =0; v<Nv;v++){
            // 条件2 ： 如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
            if(vis[v] == 0 && Graph->G[u][v]!= INF && d[u]+Graph->G[u][v]< d[v]){
                d[v] = d[u] +Graph->G[u][v]; // 优化d[v]
                pre[v] = u;
            }        
        }
    }
    printf("\n");
    DFS(pre, 0, 4);
}

int main(){

    int v_Cities, e_Roads, c1, c2;
    scanf("%d %d %d %d", &v_Cities,&e_Roads, &c1, &c2);
    printf("#city %d, #roads %d, begin %d, end %d \n", v_Cities, e_Roads, c1, c2);
    MGraph Graph = BuildGraph(v_Cities,e_Roads);
    /* Dijkstra*/
    Dijkstra(Graph,c1,c2);
    return 0;
}




