/*
题意：
    给定一个只包含正整数的非空数组 nums，
    判断能否将数组分成两个子集，
    使两个子集中的元素和相等。

思路：
    使用 0/1 背包动态规划。

    先计算数组所有元素的总和 sum。

    如果 sum 是奇数，
    不可能平均分成两个整数和相等的子集，
    直接返回 false。

    如果 sum 是偶数，
    问题转换为：
        能否从 nums 中选择一些数字，
        使它们的和恰好等于 target = sum / 2。

    定义：
        dp[j] 表示能否从已经遍历过的数字中，
        选择一些数字使它们的和恰好为 j。

    初始化：
        dp[0] = true

    表示什么数字都不选择时，
    可以组成和为 0。

    遍历每个数字 num，
    再从 target 向 num 倒序枚举 j。

    如果之前能够组成 j - num，
    那么加入当前 num 后就能够组成 j。

    状态转移：
        dp[j] = dp[j] || dp[j - num]

    j 必须从大到小遍历，
    因为每个数字只能使用一次。
    如果从小到大遍历，
    当前数字可能在同一轮中被重复使用，
    就会变成完全背包。

时间复杂度：O(n × target)
空间复杂度：O(target)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        // 计算数组总和
        for (const auto &num : nums)
        {
            sum += num;
        }

        // 总和为奇数，不可能平均分成两个整数和相同的子集
        if (sum % 2)
        {
            return false;
        }

        int target = sum / 2;

        // dp[j] 表示能否选择一些数字组成和 j
        vector<bool> dp(target + 1, false);

        // 什么都不选时可以组成和 0
        dp[0] = true;

        for (const auto &num : nums)
        {
            // 0/1 背包必须倒序遍历，保证当前 num 只使用一次
            for (int j = target; j >= num; --j)
            {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};