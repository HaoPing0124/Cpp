// 已知一个背包最多能容纳体积之和为v的物品
// 现有n个物品，第i个物品的体积为vi，重量为wi
// 求当前背包最多能装多大重量的物品?

// 模版
// 时间复杂度：O(n * V)
// 空间复杂度：O(V)

#include "Algorithm.hpp"

// 二维数组
class Solution {
  public:
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        vector<vector<int>> dp(n + 9, vector<int>(V + 9, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= V; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= vw[i - 1][0])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - vw[i - 1][0]] + vw[i - 1][1]);
            }
        }
        return dp[n][V];
    }
};

// 优化空间 一维数组
class Solution {
public:
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        vector<int> dp(V + 9, 0);
        for(int i = 0; i < n; ++i)
        {
            for(int j = V; j >= vw[i][0]; --j)
            {
                dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1]);
            }
        }
        return dp[V];
    }
};