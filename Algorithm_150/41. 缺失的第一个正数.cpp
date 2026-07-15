/*
题意：
    给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
    请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间(O(1))的解决方案。

思路：
    将原数组维护成一个：数字 nums[i] 就放入在 i 位置 的数组
    比如 数字3 就放入在 数组的第 3 位
    所以 遇到一个数字 nums[i] 时，就要判断该数字是否和下标匹配，若不匹配则交换位置
    因为数组从 0 开始，所以 第 i 个位置 应该和 nums[i - 1] 相匹配
    最后再遍历一遍数组，找到 第一个 与自身下标不匹配的数字 就是答案

时间复杂度：O(N)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            // 如果一个数在[1, n]中 并且 不重复
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                // 那么就交换两个数的位置，将 数字nums[i - 1](数组从0开始) 放到 i 上
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        // 找第一个 位置 与 数字 不匹配的数
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};