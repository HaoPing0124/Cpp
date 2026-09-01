/*
题意：
    给定一个正整数数组 nums 和正整数 target，
    找出和大于等于 target 的长度最小的连续子数组，
    返回该子数组的长度。

    如果不存在满足条件的子数组，
    返回 0。

思路：
    使用滑动窗口。

    left 表示窗口左边界，
    right 表示窗口右边界，
    sum 表示当前窗口 [left, right] 内元素之和。

    right 从左到右遍历数组，
    每加入一个 nums[right]，
    就将它累加到 sum 中。

    当：
        sum >= target

    说明当前窗口已经满足条件。

    此时不断移动 left 缩小窗口，
    在仍然满足 sum >= target 的前提下，
    尽可能得到更短的子数组。

    每次满足条件时，
    使用当前窗口长度：

        right - left + 1

    更新最小答案。

    当缩小到 sum < target 时，
    停止移动 left，
    继续让 right 向右扩展窗口。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();

        int left = 0;
        int sum = 0;
        int res = n + 1;

        for (int right = 0; right < n; ++right)
        {
            // 将当前元素加入窗口
            sum += nums[right];

            // 当前窗口满足条件时，不断缩小左边界
            while (sum >= target)
            {
                res = min(res, right - left + 1);

                // 移除窗口最左边的元素
                sum -= nums[left];
                ++left;
            }
        }

        return res == n + 1 ? 0 : res;
    }
};