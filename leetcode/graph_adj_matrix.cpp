#include <memory>
#include <cstdio>
#include <climits>

using namespace std;

class Edge{
public:
    typedef std::shared_ptr<Edge> Ptr;
    Edge(){
        scanf("%d %d %d",&V1, &V2, &Weight);
    }
    int V1;
    int V2;
    int Weight;
};

class MGraph{
public:
    typedef std::shared_ptr<MGraph> Ptr;
    static const int vm = 510;
    int Vn = 0;
    int En = 0;
    int Weight[vm][vm];
    int Data[vm];
    void Create(int vn, int en);
    void InsertEdge(Edge::Ptr edge);
};

void MGraph::Create(int vn, int en){
    Vn = vn;
    En = en;
    for(int i =0;i<vm;i++){
        for(int j =0;j<vm;j++){
            Weight[vm][vm] = INT_MAX;
        }
    }
    for(int i=0; i<vn;i++){
        scanf("%d", &Data[i]);
    }
};

void MGraph::InsertEdge(Edge::Ptr edge){
    Weight[edge->V1][edge->V2] = edge->Weight;
    Weight[edge->V2][edge->V1] = edge->Weight;
}

int main(){

    MGraph::Ptr Graph = MGraph::Ptr(new MGraph);
    int v_Cities, e_Roads, c1, c2;
    scanf("%d %d %d %d", &v_Cities,&e_Roads, &c1, &c2);
    printf("#city %d, #roads %d, begin %d, end %d \n", v_Cities, e_Roads, c1, c2);
    Graph->Create(v_Cities,e_Roads);
    for(int i=0; i<e_Roads;i++){
        Edge::Ptr edge = Edge::Ptr(new Edge);
        printf("%d th, begin: %d, end: %d, weight: %d \n", i, edge->V1, edge->V2,edge->Weight);
        Graph->InsertEdge(edge);
    }

    return 0;
}


