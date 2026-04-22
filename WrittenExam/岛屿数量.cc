// 给一个01矩阵，1代表是陆地，0代表海洋，如果两个1相邻，那么这两个1属于同一个岛。
// 我们只考虑上下左右为相邻。岛屿:相邻陆地可以组成一个岛屿(相邻:上下左右)判断岛屿个数。
// 例如:输入
// [1,1,0,0,0],
// [0,1,0,1,1],
// [0,0,0,1,1],
// [0,0,0,0,0],
// [0,0,1,1,1]
// 对应的输出为3(注:存储的01数据其实是字符'0','1')

#include "Algorithm.hpp"
class Solution {
  public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool vis[210][210] = {false};

    void dfs(vector<vector<char> >& grid, int i, int j) {
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x < n && x >= 0 && y < m && y >= 0 && grid[x][y] == '1' && !vis[x][y]) {
                dfs(grid, x, y);
            }
        }
    }
    int solve(vector<vector<char> >& grid) {
        n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};