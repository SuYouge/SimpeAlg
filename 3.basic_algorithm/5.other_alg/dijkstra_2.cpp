#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define INF 0x7777777

vector<vector<int>> map;

typedef int Node;


vector<int> find_neighbor(int cur){
    vector<int> res;
    vector<int> v = map[cur];
    for(int i =0;i<v.size();i++){
        if(v[i]!=INF) res.push_back(i);
    }
    return res;
}

// 清空队列的操作
void clear(priority_queue<int>& q) {
	priority_queue<int> empty;
	swap(empty, q);
}

int dijkstra(Node start, Node target){
    int size = map.size();
    vector<int> dist(size);
    fill(dist.begin(), dist.end(), INF);

}


int main(){
    int size = 7;
    for(int i =0;i<size;i++){
        vector<int> tmp;
        tmp.resize(size);
        fill(tmp.begin(), tmp.end(), INF);
        map.push_back(tmp);
    }
    map[A][B] = 3;
    map[A][C] = 4;
    map[A][D] = 5;
    map[B][E] = 2;
    map[C][E] = 3;
    map[C][F] = 2;
    map[D][G] = 1;
    map[F][G] = 1;

    // for(auto v:map){
    // for(auto s:v){
    //     if(s == INF){
    //         cout<<"* ";
    //     }else{
    //         cout<<s<<" ";
    //     }
    // }
    // cout<<endl;
    // }

    return 0;
}