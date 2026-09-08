/*
题意：
    给定一个按照起点升序排列、且互不重叠的区间数组 intervals，
    再给定一个新区间 newInterval。

    将 newInterval 插入 intervals 中，
    如果和已有区间发生重叠，就合并这些区间，
    最终返回仍然有序且互不重叠的区间数组。

思路：
    将整个过程分成三部分。

    第一部分：
        如果当前区间的结束位置小于 newInterval 的开始位置，
        说明它完全在新区间左边，不会重叠，
        直接加入结果。

    第二部分：
        如果当前区间的开始位置小于等于 newInterval 的结束位置，
        说明当前区间和 newInterval 有重叠，
        更新 newInterval 的左右边界进行合并。

    第三部分：
        当剩余区间已经完全位于 newInterval 右边时，
        将合并后的 newInterval 加入结果，
        再把后面的区间全部加入结果。

时间复杂度：O(n)
空间复杂度：O(n)，用于返回结果
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        // 1. 加入新区间左边完全不重叠的区间
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            ++i;
        }

        // 2. 合并所有和新区间重叠的区间
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }

        // 加入合并后的新区间
        res.push_back(newInterval);

        // 3. 加入新区间右边剩余的区间
        while (i < n)
        {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};