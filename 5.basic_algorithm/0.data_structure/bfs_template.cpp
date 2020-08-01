#include <queue>
#include <unordered_set>
using namespace std;
/**
 * Return the length of the shortest path between root and target node.
 */
typedef int Node;
int BFS(Node root, Node target) {
    queue<Node> queue;  // store all nodes which are waiting to be processed
    unordered_set<Node> used;     // store all the used nodes，unordered_set更快
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    queue.push(root);
    used.insert(root);
    // BFS
    while (!queue.empty()) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = queue.front();
            if(cur == traget) return step;
            // 下面这一步遍历取决于待搜索对象的实现
            // 对于邻接矩阵还要判断是否连通（e[cur][next]!=inf）
            for (Node next : the neighbors of cur) {
                if (used.count(next)==0) {
                    queue.push(next);
                    used.insert(next);
                }
            }
            queue.pop();
        }
    }
    return -1;          // there is no path from root to target
}