/*
题意：
    给定一个整数数组 nums，
    返回其中最长严格递增子序列的长度。

    子序列不要求在原数组中连续，
    但是不能改变元素在原数组中的相对顺序。

思路：
    使用动态规划。

    定义：
        dp[i] 表示以 nums[i] 结尾的最长递增子序列长度。

    每个 nums[i] 自己都可以组成长度为 1 的递增子序列，
    所以所有 dp[i] 初始化为 1。

    计算 dp[i] 时，
    枚举 nums[i] 前面的所有位置 j。

    如果：
        nums[j] < nums[i]

    说明 nums[i] 可以接在以 nums[j] 结尾的递增子序列后面，
    此时可以得到新的长度：
        dp[j] + 1

    因此状态转移为：
        dp[i] = max(dp[i], dp[j] + 1)

    因为最长递增子序列不一定以最后一个元素结尾，
    所以需要使用 res 记录所有 dp[i] 中的最大值。

时间复杂度：O(n²)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 1.创建 dp 表
        // 2.初始化
        // 3.填表
        // 4.返回结果

        int n = nums.size();

        // dp[i] 表示以 nums[i] 结尾的最长递增子序列长度
        vector<int> dp(n, 1);

        // nums 至少有一个元素，所以初始最长长度为 1
        int res = 1;

        for (int i = 1; i < n; ++i)
        {
            // 枚举 nums[i] 前面的所有元素
            for (int j = 0; j < i; ++j)
            {
                // nums[i] 可以接在 nums[j] 后面形成严格递增序列
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            // 最长递增子序列不一定以最后一个元素结尾
            // 保留全局最大值
            res = max(res, dp[i]);
        }

        return res;
    }
};