/*
题意：
    给定一个无重复元素的有序整数数组 nums，
    将其中连续的数字合并成若干区间。

    如果一个区间只有一个数字，
    就输出这个数字。

    如果一个区间包含多个连续数字，
    就按照 "start->end" 的格式输出。

思路：
    使用双指针扫描数组。

    left 表示当前连续区间的起点，
    right 从 left 开始向右寻找连续数字。

    如果 nums[right + 1] == nums[right] + 1，
    说明下一个数字仍然属于当前连续区间，
    right 继续右移。

    当无法继续连续时，
    当前区间就是 [nums[left], nums[right]]。

    如果 left == right，
    说明区间只有一个数字，
    直接加入 nums[left]。

    否则加入：
        nums[left] + "->" + nums[right]

    然后从 right + 1 开始寻找下一个区间。

时间复杂度：O(n)
空间复杂度：O(1)，不计算返回结果
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;

        int n = nums.size();
        int left = 0;

        while (left < n)
        {
            int right = left;

            // 向右寻找连续区间
            while (right + 1 < n && nums[right + 1] == nums[right] + 1)
            {
                ++right;
            }

            // 当前区间只有一个数字
            if (left == right)
            {
                res.push_back(to_string(nums[left]));
            }
            else
            {
                res.push_back(
                    to_string(nums[left]) + "->" + to_string(nums[right]));
            }

            // 开始寻找下一个区间
            left = right + 1;
        }

        return res;
    }
};