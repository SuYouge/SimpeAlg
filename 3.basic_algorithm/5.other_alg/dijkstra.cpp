
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
const int mx = 10005;

typedef pair<double, int> P; // first是最短距离，second是顶点编号
struct edge
{
    double cost;
    int to;
    void read()
    {
        scanf("%d%lf", &to, &cost);
        // printf("to %d cost %.2f \n", to, cost);
    }
} e;

vector<edge> G[mx];
double disTo[mx];
priority_queue<P, vector<P>, greater<P>> pq;

/*
使用：dj(起点)
输出：disTo[目标点]
复杂度：平均情况：O(ElogV)，最坏情况：O(ElogV)
*/
void dj(int s)
{
    P p;
    int v, i;
    memset(disTo, 100, sizeof(disTo));
    disTo[s] = 0.0;
    while (!pq.empty())
        pq.pop();
    pq.push(P(0.0, s));
    while (!pq.empty())
    {
        p = pq.top(), pq.pop(); // 逗号表达式
        v = p.second;           // v视作e.from
        if (p.first > disTo[v])
            continue;
        for (i = 0; i < G[v].size(); ++i)
        {
            e = G[v][i];
            if (disTo[e.to] > disTo[v] + e.cost) ///v视作e.from
            {
                disTo[e.to] = disTo[v] + e.cost;
                pq.push(P(disTo[e.to], e.to));
            }
        }
    }
}

int main()
{
    int n, m, i, a;
    scanf("%d%d", &n, &m);
    {
        for (i = 0; i < n; ++i)
            G[i].clear();
        while (m--)
        {
            scanf("%d", &a); // from
            e.read();        // to cost
            G[a].push_back(e);
        }
        dj(0);
        for (i = 1; i < n; ++i)
            printf("%d %.2f\n", i, disTo[i]);
    }
    return 0;
}
/*
7 8
0 1 3
0 2 4
0 3 5
1 4 2
2 4 3
2 5 2
5 6 1
3 6 5
*/