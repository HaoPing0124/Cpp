/*
题意：
    给定一个整数数组 nums，
    找出乘积最大的非空连续子数组，
    返回该子数组对应的最大乘积。

思路：
    使用动态规划。

    因为当前数字可能是负数，
    负数会让最大值和最小值发生交换，
    所以需要同时维护：

        maxF：
            以当前位置结尾的最大乘积。

        minF：
            以当前位置结尾的最小乘积。

    遍历到 nums[i] 时，
    当前乘积有三种来源：

        1. 只选择 nums[i]；
        2. nums[i] 接在之前最大乘积后面；
        3. nums[i] 接在之前最小乘积后面。

    因此：

        maxF = max(nums[i], max(preMax * nums[i], preMin * nums[i]))

        minF = min(nums[i], min(preMax * nums[i], preMin * nums[i]))

    注意：
        更新 maxF 和 minF 时必须使用上一轮的旧值，
        不能先修改 maxF 后再用新的 maxF 计算 minF。

    最后使用 res 保存所有位置中的最大乘积。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // 以当前位置结尾的最大乘积
        int maxF = nums[0];

        // 以当前位置结尾的最小乘积
        int minF = nums[0];

        // 保存全局最大乘积
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            // 保存上一轮状态，防止更新后覆盖
            int preMax = maxF;
            int preMin = minF;

            // 当前最大乘积可能来自当前数字、之前最大值或之前最小值
            maxF = max(nums[i], max(preMax * nums[i], preMin * nums[i]));

            // 当前最小乘积也需要同步维护
            minF = min(nums[i], min(preMax * nums[i], preMin * nums[i]));

            // 更新全局最大值
            res = max(res, maxF);
        }

        return res;
    }
};