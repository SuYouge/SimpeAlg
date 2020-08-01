/*
    path planing simulator
*/
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <cmath>
#include <map>
using namespace std;

class point;
class expand_object;

// typedef vector<point> row_t;  // path type
typedef vector<vector<point>> map_t; // map type
typedef vector<point> path_t;        // path type
typedef vector<expand_object> expand_list_t;

// int p = 0;
double threshold = 0.35;
class point
{
public:
    point() {}
    point(int x, int y) : x(x), y(y) {}
    int x = 0, y = 0; // grid center
    int type = 2;     // 障碍物为-1 目标为0 起点为1 其余为2
};

// open list对象
class open_object
{
public:
    bool on_list;
    point self;
    point parent;
    double h = 0.0;
    double g = 0.0;
    double f = 0.0;
};

// expand array对象
class expand_object
{
public:
    point self;
    double h = 0.0;
    double g = 0.0;
    double f = 0.0;
};

double distance(point &p1, point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


// 返回值map为一个二维数组， 每一个元素都是一个点
map_t obstacle_map(int xStart, int yStart, int xTarget, int yTarget, int MAX_X, int MAX_Y)
{
    assert((xTarget <= MAX_X - 1) || (yTarget <= MAX_Y - 1));
    map_t map;
    // vector<point> tmp(MAX_X);       // X表示宽度
    for (int i = 0; i < MAX_Y; i++) // Y表示高度
    {
        // tmp.clear();
        vector<point> tmp;              // X表示宽度
        for (int j = 0; j < MAX_X; j++) // 遍历X方向
        {
            double r = (rand() % 100) / 100.0;
            point ap(j, i); // 构造点
            if (r < threshold)
            {
                ap.type = -1; // 障碍物
            }
            else
            {
                ap.type = 2;
            }
            tmp.push_back(ap);
        }
        map.push_back(tmp); // 将一行插入
    }
    map[yStart][xStart].type = 1;
    map[yTarget][xTarget].type = 0;
    return map;
}

//
open_object insert_open(point self, point parent, double h, double g, double f)
{
    open_object ob;
    ob.on_list = true;
    ob.self = self;
    ob.parent = parent;
    ob.h = h;
    ob.g = g;
    ob.f = f;
    return ob;
}

void print_state(double goal_distance, double path_cost, int open_num)
{
    printf("goal_distance = %f \n", goal_distance);
    printf("path_cost = %f \n", path_cost);
    printf("open-list size = %d \n", open_num);
}

int min_fn(vector<open_object> open_list, point Target)
{ // 用优先级队列优化？
    int t = 0;
    bool flag = false; // 到达目标的flag
    int goal_index = 0;
    vector<pair<open_object, int>> tmp_array;
    for (auto it = open_list.begin(); it != open_list.end(); it++)
    {
        if (it->on_list == true) // 未访问过
        {
            tmp_array.push_back(make_pair(*it, it - open_list.begin()));
            if ((it->self.x == Target.x) && (it->self.y == Target.y))
            {
                flag = true;
                goal_index = it - open_list.begin();
            }
        }
    }
    // int res = -1;
    int min_id = -1;
    double min_f = 100000.0;
    if (tmp_array.size() != 0)
    {
        for (auto it = tmp_array.begin(); it != tmp_array.end(); it++)
        {
            if (it->first.f < min_f)
            {
                min_id = it->second;
                min_f = it->first.f;
            }
        }
        // res = min_id;
    }
    // printf("the node with smallest f is %d , f = %f \n", res, min_f);
    return min_id;
}

expand_list_t expand_array(point &Node_expanded, double g_expanded,
                           point &Target, vector<point> &closed_list, int MAX_X, int MAX_Y)
{
    expand_list_t res;
    vector<pair<int, int>> dxdy;
    dxdy.push_back(make_pair(0, 1)); // 8连通
    dxdy.push_back(make_pair(0, -1));
    dxdy.push_back(make_pair(-1, 0));
    dxdy.push_back(make_pair(1, 0));
    dxdy.push_back(make_pair(1, 1));   // ru
    dxdy.push_back(make_pair(1, -1));  // rd
    dxdy.push_back(make_pair(-1, 1));  // lu
    dxdy.push_back(make_pair(-1, -1)); // ld
    int xx = 0;
    int yy = 0;
    bool flag = false;
    expand_object exp;
    for (int i = 0; i < 8; i++)
    {
        yy = Node_expanded.y + dxdy[i].first;
        xx = Node_expanded.x + dxdy[i].second;
        if ((xx >= 0 && xx < MAX_X) && (yy >= 0 && yy < MAX_Y))
        { // 不能超过地图大小
            flag = true;
            for (auto it = closed_list.begin(); it != closed_list.end(); it++)
            {
                if ((xx == it->x) && (yy == it->y))
                { // 邻域处在closed list内
                    flag = false;
                }
            }
            if (flag == true)
            {
                exp.self.x = xx;
                exp.self.y = yy;
                exp.h = distance(Target, exp.self);
                exp.g = g_expanded + distance(Node_expanded, exp.self);
                exp.f = exp.h + exp.g;
                // printf("expanded point (%d, %d) \n", xx, yy);
                res.push_back(exp);
            }
        }
    }
    return res;
}

int node_index(vector<open_object> &open_list, point p)
{
    int res = -1;
    for (auto it = open_list.begin(); it != open_list.end(); it++)
    {
        if ((it->self.x == p.x) && (it->self.y == p.y))
        {
            res = it - open_list.begin();
        }
    }
    return res;
}

int open_list_empty(vector<open_object> &open_list)
{
    int cnt_opsize = 0;
    for (auto it = open_list.begin(); it != open_list.end(); it++)
    {
        if (it->on_list)
        {
            cnt_opsize++;
        }
    }
    return cnt_opsize;
}

// 返回值path为一个数组， 每一个元素都是一个点
path_t A_star_search(const map_t &map, int MAX_X, int MAX_Y, int xStart, int yStart, int xTarget, int yTarget)
{
    vector<open_object> open_list;
    vector<point> closed_list;

    // 障碍物初始化closed_list
    int h = map.size();
    int w = map[0].size();
    int obstacle_cnt = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j].type == -1)
            {
                closed_list.push_back(map[i][j]);
                obstacle_cnt++;
            }
        }
    }
    // printf("%d have been pushed into closed_list \n", obstacle_cnt);
    // 初始化
    int closed_num = closed_list.size();
    point Node = map[yStart][xStart];     // 起点
    point Target = map[yTarget][xTarget]; // 目标
    printf("起点： %d %d  目标： %d %d %d\n", Node.x, Node.y, Target.x, Target.y, Target.type);
    double goal_distance = distance(Node, Target); // 初始化目标距离，启发式距离
    double path_cost = 0;                          // 初始化代价
    open_object open = insert_open(Node, Target, goal_distance, path_cost, goal_distance);
    open_list.push_back(open);
    // open_list[0].on_list = true; // 不必要
    int open_num = open_list.size();                 // 初始化open-list size
    print_state(goal_distance, path_cost, open_num); // print_state
    bool no_path = true;                             // 初始化搜索成功flag
    closed_list.push_back(Node);                     // 将起点加入closed_list， 访问结束
    // 初始化结束
    int min_index = 0; // 优先级队列中的最低元素索引
    point Node_expanded;
    double g_expanded = 0.0;
    while (1)
    {
        // 1. If the queue is empty, return FALSE; break
        if (open_list_empty(open_list) == 0)
            break; // 如果open list为空则退出
        // 2. Remove the node “n” with the lowest f(n)=g(n)+h(n) from the priority queue
        min_index = min_fn(open_list, Target); // 这里可能返回-1
        // printf("found min_index =  %d\n", min_index);
        if (min_index == -1)
            break; // 如果open list为空则退出
        // 3. Mark node “n” as expanded, 将min_index的节点标记为扩展，并将节点标记为已访问
        Node_expanded = open_list[min_index].self;
        g_expanded = open_list[min_index].g;
        open_list[min_index].on_list = false;

        // 将当前Node_expanded加入closed list
        closed_list.push_back(Node_expanded);
        // printf("point (%d, %d) expanded \n", Node_expanded.x, Node_expanded.y);

        // 4. If the node “n” is the goal state, return TRUE; break; 如果扩展的点就是目标点
        if ((Node_expanded.x == Target.x) && (Node_expanded.y == Target.y))
        {
            no_path = false;
            printf("path found \n");
            break;
        }
        // 5. For all unexpanded neighbors “m” of node “n”
        expand_list_t expand_list = expand_array(Node_expanded, g_expanded,
                                                 Target, closed_list, MAX_X, MAX_Y);
        if (expand_list.size() != 0)
        {
            for (int i = 0; i < expand_list.size(); i++)
            {
                Node = expand_list[i].self;
                int n_index = node_index(open_list, Node);
                if (n_index == -1)
                { // isempty
                    double hn = distance(Node, Target);
                    double gn = g_expanded + distance(Node, Node_expanded);
                    double fn = gn + hn;
                    open_object op;
                    op.self = Node;
                    op.parent = Node_expanded;
                    op.h = hn;
                    op.g = gn;
                    op.f = fn;
                    op.on_list = true;
                    open_list.push_back(op);
                    // printf("point (%d, %d) open_list pushed type = %d \n", op.self.x, op.self.y, op.self.type);
                }
                else
                {
                    if (open_list[n_index].g > g_expanded + distance(Node, Node_expanded))
                    {
                        open_list[n_index].parent = Node_expanded; // 父节点
                        open_list[n_index].g = distance(Node, Node_expanded);
                        open_list[n_index].f = open_list[n_index].h + open_list[n_index].g;
                        // printf("update parent type = %d \n", Node_expanded.type);
                    }
                }
            }
        }
    }
    // printf("recurse path ---\n");
    path_t path;
    point waypoint;
    if (!no_path)
    {
        waypoint = Target;
        int index = node_index(open_list, waypoint);
        path.push_back(waypoint);
        while (index > 0)
        {
            assert(open_list[index].on_list == false);
            assert(open_list[index].self.type != -1);
            waypoint = open_list[index].parent;
            index = node_index(open_list, waypoint);
            path.push_back(waypoint);
        }
        assert(index == 0);
        waypoint = open_list[index].parent;
        path.push_back(waypoint);
    }
    return path;
}

bool in_path(int i, int j, const path_t &path)
{
    bool res = false;
    for (auto it = path.begin(); it != path.end(); it++)
    {
        if ((it->x == j) && (it->y == i))
        {
            res = true;
        }
    }
    return res;
}

// void output_only_map(const map_t &map)
// {
//     int h = map.size();
//     int w = map[0].size();
//     for (int i = 0 ; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             if (map[i][j].type == -1)
//             {
//                 printf("\033[2;31;1m%2d \033[2;7;0m", map[i][j].type);
//             }
//             else
//             {
//                 printf("%2d ", map[i][j].type);
//             }
//         }
//         printf("\n");
//     }
//     // cout << "exiting output_map" << endl;
// }

void output_map(const map_t &map, const path_t &path)
{
    // for(auto it = path.begin();it!=path.end();it++){
    //     printf("waypoint (%d, %d) with type %d \n", it->x, it->y, it->type);
    // }
    if (path.size() == 0)
    {
        printf("no path found \n");
        return;
    }
    int h = map.size();
    int w = map[0].size();
    for (int i = 0 ; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (in_path(i, j, path))
            {
                printf("\033[2;7;1m%2d \033[2;7;0m", map[i][j].type);
                // printf(" * ");
            }else if(map[i][j].type == -1){
                printf("\033[3;8;1m%2d \033[2;7;0m", map[i][j].type);
            }
            else
            {
                printf("%2d ", map[i][j].type);
            }
        }
        printf("\n");
    }
    // cout << "exiting output_map" << endl;
}

int main()
{
    // 设置变量
    int MAX_X = 25;
    int MAX_Y = 24;
    int xStart = 0;          // 第1列
    int yStart = 0;          // 第1行
    int xTarget = MAX_X - 1; // 第5列
    int yTarget = MAX_Y - 1; // 第10行

    // 构造地图
    map_t map = obstacle_map(xStart, yStart, xTarget, yTarget, MAX_X, MAX_Y);
    // output_only_map(map);
    // 进行路径规划
    path_t path = A_star_search(map, MAX_X, MAX_Y, xStart, yStart, xTarget, yTarget);

    // 输出地图
    output_map(map, path);
    // cout << "exting main ---" << endl;
    return 0;
}