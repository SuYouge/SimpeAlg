#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;


class Solution {
  public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visited;
    int key;
    int yl;
    int xl;
    // int cnt = 0;
    int getsum(point &p) {
        string y = to_string(p.first);
        string x = to_string(p.second);
        int sum = 0;
        for (auto dy : y) {
            sum += (dy - '0');
        }
        for (auto dx : x) {
            sum += (dx - '0');
        }
        // cout<<"reach "<<y<<" "<<x<<" with sum = "<<sum<<endl;
        return sum;
    }

    vector<point> find_neighbor(point p) {
        // if (getsum(p) > key)
        //     return {};
        vector<point> res;
        for (auto d : dir) {
            int y = p.first + d.first;
            int x = p.second + d.second;
            point yx = make_pair(y,x);
            if (y >= 0 && y < yl) {
                if (x >= 0 && x < xl) {
                    if (visited[y][x] != 1 && getsum(yx) <= key) {
                        res.push_back({y, x});
                        // cout<<"reach "<<y<<" "<<x<<endl;
                        // cnt++;
                    }
                }
            }
        }
        return res;
    }

  public:
    int movingCount(int m, int n, int k) {
        for (int i = 0; i < m; i++) {
            vector<int> tmp(n, 0);
            visited.push_back(tmp);
        }
        yl = m;
        xl = n;
        key = k;
        stack<point> s;
        s.push({0, 0});
        visited[0][0] = 1;
        // cnt++;
        while (!s.empty()) {
            point p = s.top();
            s.pop();
            visited[p.first][p.second] = 1;
            // cout<<p.first<<" "<<p.second<<" has neighbor"<<endl;
            vector<point> list = find_neighbor(p);
            for (auto l : list) {
                // cout<<l.first<<" "<<l.second<<endl;
                s.push(l);
            }
        }
        int cnt = 0;
        for(auto v:visited){
            for(auto s:v){
                if(s==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution so;
    cout << so.movingCount(3, 2, 17);
    return 0;
}