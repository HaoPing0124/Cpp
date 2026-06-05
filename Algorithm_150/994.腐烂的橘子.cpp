// 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
// 值 0 代表空单元格；
// 值 1 代表新鲜橘子；
// 值 2 代表腐烂的橘子。
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

// 多源BFS + 最短路径
#include "Algorithm_150.h"

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;
        int res = 0;
        
        for(int i = 0; i < n; ++i)   
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    vis[i][j] = true;
                }

        while(q.size())
        {
            res++;
            int sz = q.size();
            while(sz--)
            {
                auto [a, b] = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i)
                {
                    int x = a + dx[i];
                    int y = b + dy[i];
                    if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 1)
                    {
                        vis[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(!vis[i][j] && grid[i][j] == 1)
                    return -1;

        return res ? res - 1 : 0;
    }
};