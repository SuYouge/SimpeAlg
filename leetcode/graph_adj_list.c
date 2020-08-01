/* Directed Graph */
/* Undirected Graph*/
/* C style */

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

typedef int DataType ;
typedef int Vertex;
typedef int WeightType;
const int MaxVertexNum = 510;
#define INF (0x6fffffff)

typedef struct GNode* PtrToGNode;

/* Pointer to vertex */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV; // vertex ID
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct Vnode
{
    PtrToAdjVNode FirstEdge; // Every node has a First Edge pointer
    DataType Data;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G; // array of every node (with their headpointer)
};
typedef PtrToGNode LGraph;

/* Edge datastructure */
typedef struct ENode* PtrToEdge;
struct ENode
{   
    Vertex V1, V2; // directed
    WeightType Weight;
};
typedef PtrToEdge Edge; // instance


LGraph CreateGraph(int VertexNum){

    Vertex V, W;

    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));

    Graph -> Nv = VertexNum;
    Graph -> Ne = 0;

    for(V =0; V<Graph->Nv;V++){
        Graph->G[V].FirstEdge = NULL; // init every head pointer
    }
    return Graph;
}

void InsertEdge (LGraph Graph, Edge E){

    PtrToAdjVNode NewNode;
    /* insert <v1,v2>*/
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode -> AdjV = E->V2;
    NewNode -> Weight = E-> Weight;
    /* insert v2 to v1 head */
    NewNode -> Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
    /* for undirected graph , insert<v2,v1>*/
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode -> AdjV = E->V1;
    NewNode -> Weight = E-> Weight;
    /* insert v2 to v2 head */
    NewNode -> Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;

    printf("Insert between %d an %d with weight: %d \n", E->V1,E->V2,E->Weight);
}

LGraph BuildGraph(int v_Cities, int e_Roads){
    LGraph Graph;
    Edge E;
    int Nv, i;
    Nv = v_Cities;

    Graph = CreateGraph(Nv);

    Graph->Ne = e_Roads;

    for(int V=0; V<Graph->Nv; V++){
        scanf("%d", &(Graph->G[V].Data));
        printf("%d ", Graph->G[V].Data);
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
    return Graph;
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

void Dijkstra(LGraph Graph, int begin, int end){
    WeightType d[MaxVertexNum];
    Vertex vis[MaxVertexNum];
    Vertex pre[MaxVertexNum];
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    int Nv = Graph->Nv;
    for(Vertex i=0; i<Nv; i++) {d[i] = (i==begin)? 0 : INF; }
    for(Vertex i=0;i<Nv; i++){
        printf("\n");
        for(Vertex i=0;i<Nv;i++) {printf("step %d: %d ", i, d[i]);}
        int u=-1; WeightType MIN = INF;
        for(Vertex j=0;j<Nv;j++){
            if(vis[j]==0 && d[j]<MIN){
                u = j;
                MIN = d[j];
            }
        }
        if (u==-1) return;
        vis[u] = 1;
        PtrToAdjVNode _next = Graph->G[u].FirstEdge;
        while(_next != NULL){
            Vertex v = _next->AdjV;
            WeightType _weight = _next->Weight;
            if(vis[v] == 0 && d[u] + _weight < d[v]){
                d[v] = d[u] + _weight;
                pre[v] = u;
            }
            _next = _next->Next;
        }
    }
    printf("\n");
    DFS(pre, 0, 4);
}


int main(){

    int v_Cities, e_Roads, c1, c2;
    scanf("%d %d %d %d", &v_Cities,&e_Roads, &c1, &c2);
    printf("#city %d, #roads %d, begin %d, end %d \n", v_Cities, e_Roads, c1, c2);
    LGraph Graph = BuildGraph(v_Cities,e_Roads);
    /* Dijkstra*/
    Dijkstra(Graph,c1,c2);
    return 0;
}