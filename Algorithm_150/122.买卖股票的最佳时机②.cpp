//122.买卖股票的最佳时机②
//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
//在每一天，你可以决定是否购买和 / 或出售股票。
//你在任何时候 最多 只能持有 一股 股票。
//然而，你可以在 同一天 多次买卖该股票，但要确保你持有的股票不超过一股。
//返回 你能获得的 最大 利润 。

#include"Algorithm_150.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
