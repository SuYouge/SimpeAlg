#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<char>> b;  // bool地图
    vector<vector<char>> bd; // 实际地图
    vector<pair<int, int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    stack<pair<int, int>> path; // 路径
    string wd;                  // 待比较的字符串
    int h;
    int w;
    bool bres = false;

  public:
    vector<vector<char>> bmap(int h, int w) {
        vector<vector<char>> res;
        for (int i = 0; i < h; i++) {
            vector<char> tmp(w);
            fill(tmp.begin(), tmp.end(), ' ');
            res.push_back(tmp);
        }
        return res;
    }

    void backtrack(stack<pair<int, int>> &path) {
        // cout<<"path.top.y = "<<path.top().first
        // <<" x =" <<path.top().second<<endl;
        if (path.size() == wd.length() &&
            bd[path.top().first][path.top().second] == wd[wd.length() - 1]) {
            bres = true;
            // cout<<"result path .size() = "<<path.size()<<endl;
            // cout<<"arrived "<<path.top().first<<" "<<path.top().second<<endl;
        }
        for (auto d : dir) {
            int y = path.top().first + d.first;
            int x = path.top().second + d.second;
            // cout << "path size = " << path.size() << endl;
            if (y > h - 1 || y < 0 || x > w - 1 || x < 0 || b[y][x] == '*') {
                // cout<<"trying -- y = "<<y<<" x = "<<x<<endl;
                continue;
            } else if (wd[path.size()] == bd[y][x]) {
                // cout << "trying -- y = " << y << " x = " << x << endl;
                b[y][x] = '*';
                path.push({y, x});
                backtrack(path);
                path.pop();
                b[y][x] = ' ';
            }
        }
    }

    bool exist(vector<vector<char>> &board, string word) {
        wd = word;
        h = board.size();
        w = board[0].size();
        b = bmap(h, w);
        bd = board;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (bd[i][j] == word[0]) {
                    path.push({i, j});
                    // cout << "init -- y = " << i << " x = " << j << endl;
                    // cout<<"path size = "<<path.size();
                    b[i][j] = '*';
                    backtrack(path);
                    path.pop();
                    b[i][j] = ' ';
                    if (bres == true)
                        return bres;
                }
            }
        }
        return bres;
    }
};

int main() {
    vector<vector<char>> board = {
        {'a', 'a', 'c', 'e'}, 
        {'s', 'f', 'c', 's'}, 
        {'a', 'd', 'e', 'e'}};
    string word = "asa";
    Solution so;
    cout << so.exist(board, word);

    return 0;
}