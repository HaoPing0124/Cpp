// 给定一个 n 个节点的邻接矩阵 m。 节点定义为城市
// 如果 a 城市与 b 城市相连， b 与 c 城市相连，尽管 a 与 c 并不直接相连
// 但可以认为 a 与 c 相连，定义 a,b,c 是一个城市群。
// 矩阵 m[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，否则表示不相连。
// 请你找出共有多少个城市群。
// 数据范围: 1 ≤ n ≤ 200， 矩阵中只包含 0 和 1

// dfs
#include "Algorithm.hpp"

class Solution
{
public:
    bool vis[210] = {0};
    int citys(vector<vector<int>> &m)
    {
        int res = 0;
        for (int i = 0; i < m.size(); ++i)
        {
            if (!vis[i])
            {
                res++;
                dfs(m, i);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &m, int pos)
    {
        vis[pos] = true;
        for (int i = 0; i < m.size(); ++i)
        {
            if (!vis[i] && m[pos][i])
            {
                dfs(m, i);
            }
        }
    }
};