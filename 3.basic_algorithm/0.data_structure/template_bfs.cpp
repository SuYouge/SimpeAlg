#include <queue>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
/**
 * Return the length of the shortest path between root and target node.
 */

# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6

vector<vector<int>> map;

typedef int Node;

void find_neighbor(vector<int>& neighbor,int cur){
    vector<int> v = map[cur];
    for(int i =0;i<v.size();i++){
        if(v[i]==1) neighbor.push_back(i);
    }
}

int BFS(Node root, Node target) {
    queue<Node> queue;  // 队列中保存准备处理的节点
    unordered_set<Node> used;     // 保存所有处理过的节点，unordered_set更快
    int step = 0;       // 根到当前节点的距离
    // initialize
    queue.push(root);
    used.insert(root);
    // BFS
    while (!queue.empty()) {
        // iterate the nodes which are already in the queue
        // step += 1;
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = queue.front();
            if(cur == target) return step;
            // 下面这一步遍历取决于待搜索对象的实现
            // 对于邻接矩阵还要判断是否连通（e[cur][next]!=inf）
            vector<int> neighbor; // 不要预先分配
            find_neighbor(neighbor, cur);
            for (Node next : neighbor) {
                if (used.count(next)==0) {
                    queue.push(next);
                    used.insert(next);
                }
            }
            queue.pop();
        }
        step = step + 1;
    }
    return -1;          // there is no path from root to target
}

int main(){
    // 构造一张图, 7*7
    int size = 7;
    for(int i =0;i<size;i++){
        vector<int> tmp;
        tmp.resize(size);
        map.push_back(tmp);
    }
    map[A][B] = 1;
    map[A][C] = 1;
    map[A][D] = 1;
    map[B][E] = 1;
    map[C][E] = 1;
    map[C][F] = 1;
    map[D][G] = 1;
    map[F][G] = 1;
    map[E][G] = 1; //
    map[A][E] = 1; //
    // for(auto v:map){
    //     for(auto s:v){
    //         cout<<s<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"A->G step = "<<BFS(A, G)<<endl;
    cout<<"A->A step = "<<BFS(A, A)<<endl;;
    cout<<"A->F step = "<<BFS(A, F)<<endl;
    cout<<"C->E step = "<<BFS(C, E)<<endl;
    cout<<"D->A step = "<<BFS(D, A)<<endl;
    cout<<"E->G step = "<<BFS(E, G)<<endl;
    return 0;
}