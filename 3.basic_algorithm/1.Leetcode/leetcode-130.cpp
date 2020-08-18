#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    // vector<vector<char>> reserve;
    // vector<vector<char>> bd;
    int h, w;
    // void init_reserve() {
    //     for (int i = 0; i < h; i++) {
    //         vector<char> tmp(w);
    //         fill(tmp.begin(), tmp.end(), ' ');
    //         reserve.push_back(tmp);
    //     }
    // }

  public:
    void bfs(pair<int, int> start,vector<vector<char>>& board ) {
        queue<pair<int, int>> q;
        q.push(start);
        board[start.first][start.second] = '#';
        // reserve[start.first][start.second] = '*'; // 不要漏掉起点
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> tmp = q.front();
                q.pop();
                for (auto d : dir) {
                    int y = tmp.first + d.first;
                    int x = tmp.second + d.second;
                    if (y < 0 || x < 0 || y > h - 1 || x > w - 1) {
                        continue;
                    } else if (board[y][x] == '#') {
                        continue;
                    }
                    if (board[y][x] == 'O') {
                        board[y][x] = '#';
                        q.push({y, x});
                    }
                }
            }
        }
    }

  public:
    void solve(vector<vector<char>> &board) {
        h = board.size();
        if (h == 0)
            return;
        w = board[0].size();
        // bd = board;
        if (w == 0)
            return;
        // 任何不在边界上， 且不与边界上的0相连的最终都会被填充
        // init_reserve();
        for (int i = 0; i < w; i++) { // 最上最下两行
            if (board[0][i] == 'O' ) // 
                bfs({0, i}, board);
            if (board[h - 1][i] == 'O')
                bfs({h - 1, i}, board);
        }
        for (int i = 1; i < h - 1; i++) { // 最左最右两列
            if (board[i][0] == 'O')
                bfs({i, 0}, board);
            if (board[i][w - 1] == 'O')
                bfs({i, w - 1}, board);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};


int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    Solution so;
    so.solve(board);
    for (auto v : board) {
        for (auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}