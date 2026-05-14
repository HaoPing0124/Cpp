// 在一个m * n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值(价值大于0)。
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
// 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物?
// 如输入这样的一个二维数组，
// [1,3,1],
// [1,5,1],
// [4,2,1]
// 那么路径1 -> 3 -> 5 -> 2 -> 1 可以拿到最多价值的礼物，价值为12

// 动态规划 —— 线性dp
// 时间复杂度：O(n * m)
// 空间复杂度：O(n * m)
#include "Algorithm.hpp"

class Solution {
  public:
    int maxValue(vector<vector<int> >& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n + 9, vector<int>(m + 9));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};