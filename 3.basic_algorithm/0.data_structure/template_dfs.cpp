
// boolean DFS(Node cur, Node target, Set<Node> visited) {
//     return true if cur is target;
//     for (next : each neighbor of cur) {
//         if (next is not in visited) {
//             add next to visted;
//             return true if DFS(next, target, visited) == true;
//         }
//     }
//     return false;
// }

#include <queue>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

/*
 * Return true if there is a path from cur to target.
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
vector<Node> path;

vector<Node> find_neighbor(int cur){
    vector<Node> neighbor;
    vector<int> v = map[cur];
    for(int i =0;i<v.size();i++){
        if(v[i]==1) neighbor.push_back(i);
    }
    return neighbor;
}

// bool DFS(Node curr, Node target, unordered_set<Node> visited) {
//     if(curr == target){
//         return true;
//     }else{
//         auto neighbor = find_neighbor(curr);
//         for(auto n : neighbor){
//             if(visited.count(n) == 0){
//                 visited.insert(n);
//                 path.push_back(n); // 
//                 if(DFS(n, target, visited)==true){
//                     return true;
//                 }
//                 // visited.erase(n);
//                 path.pop_back(); // 
//             }
//         }
//     }
//     return false;          // there is no path from root to target
// }

bool DFS(Node root, Node target, unordered_set<Node> visited){
    // unordered_set<Node> visited;
    stack<Node> s;
    s.push(root);
    while(!s.empty()){
        Node curr = s.top();
        s.pop();
        if(curr == target){
            return true;
        }
        vector<Node> neighbor = find_neighbor(curr);
        for(Node n : neighbor){
            if(visited.count(n)==0){
                s.push(n);
                visited.insert(n);
            }
        }
    }
    return false;
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
    map[E][G] = 1;
    // for(auto v:map){
    //     for(auto s:v){
    //         cout<<s<<" ";
    //     }
    //     cout<<endl;
    // }
    unordered_set<Node> visited;
    cout<<"A->G step = "<<DFS(A, G, visited)<<endl;
    for(auto n : path){
        cout<<n<<"--->";
    }
    cout<<endl; path.clear();
    cout<<"A->C step = "<<DFS(A, C, visited)<<endl;
    cout<<"A->A step = "<<DFS(A, A, visited)<<endl;
    cout<<"C->G step = "<<DFS(C, G, visited)<<endl;
    cout<<"A->F step = "<<DFS(A, F, visited)<<endl;
    cout<<"C->E step = "<<DFS(C, E, visited)<<endl;
    cout<<"D->A step = "<<DFS(D, A, visited)<<endl;
    cout<<"A->D step = "<<DFS(A, D, visited)<<endl;
    cout<<"E->G step = "<<DFS(E, G, visited)<<endl;
    cout<<"E->D step = "<<DFS(E, D, visited)<<endl;

    return 0;
}