// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。

#include "Algorithm_150.h"

// bfs解法
class Solution1
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    res++;
                    q.push({i, j});
                    vis[i][j] = true;

                    while (q.size())
                    {
                        auto [a, b] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            int x = a + dx[k];
                            int y = b + dy[k];
                            if (x >= 0 && x < n && y >= 0 && y < m &&
                                !vis[x][y] && grid[x][y] == '1')
                            {
                                vis[x][y] = true;
                                q.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};


// dfs解法
class Solution2 {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m, res;
    vector<vector<bool>> vis;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(grid[i][j] == '0') return;
        vis[i][j] = true;
        for(int k = 0; k < 4; ++k)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }
};