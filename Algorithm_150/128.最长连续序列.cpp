/*
题意：
    给定一个未排序的整数数组 nums，
    找出数字连续序列的最长长度。
    连续序列中的数字不要求在原数组中相邻。
    例如：
        nums = [100,4,200,1,3,2]
        连续序列：1,2,3,4
        长度：4
思路：
    使用 unordered_set 保存数组中的所有数字。
    暴力方法需要排序：排序后遍历寻找连续数字。
    但是排序会产生：O(nlogn)
    不满足题目要求的 O(n)。

    优化：
        对于一个数字 x：
            如果 x - 1 存在，
            说明 x 不是连续序列起点。
            例如：
                2 前面有 1，
                所以 2 不需要作为开始查找。
        只有满足：
            x - 1 不存在
        的数字才可能是连续序列起点。

    从起点开始：
        x,
        x + 1,
        x + 2,
        ...
    不断在哈希集合中查找，
    统计连续长度。

    每个数字最多被向后查找一次，
    所以整体时间复杂度仍然是 O(n)。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // 保存所有数字，方便 O(1) 平均时间查找
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        for (auto &x : st)
        {
            // 如果 x 前面存在 x-1，
            // 说明 x 不是连续序列起点，跳过
            if (st.find(x - 1) != st.end()) continue;
            
            // 当前数字作为连续序列起点
            int y = x + 1;

            // 不断寻找后面的连续数字
            while (st.find(y) != st.end()) y++;

            // y 停在第一个不存在的数字位置
            // 当前序列长度为 y - x
            res = max(res, y - x);
        }
        return res;
    }
};
