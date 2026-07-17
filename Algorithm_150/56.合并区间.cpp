/*
题意：
    给你一个区间数组 intervals，其中 intervals[i] = [left, right]
    表示一个闭区间。请你合并所有相互重叠的区间，
    并返回合并后所有互不重叠的区间。

思路：
    先按照区间左端点从小到大排序，
    排序后可能发生重叠的区间会排列在一起。

    依次遍历每个区间：
    如果结果数组为空，或者最后一个合并区间的右端点
    小于当前区间的左端点，说明两个区间不重叠，
    将当前区间直接加入结果数组。

    否则说明当前区间与最后一个合并区间发生重叠，
    将最后一个合并区间的右端点更新为两个右端点的最大值。

时间复杂度：O(N log N)
    排序需要 O(N log N)，遍历合并需要 O(N)。

空间复杂度：O(N)
    结果数组最坏需要保存 N 个互不重叠的区间。
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        // 先排序保证 intervals[i][0] 的位置一定是升序，这样才不会漏判
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); ++i)
        {
            int L = intervals[i][0], R = intervals[i][1];

            // 如果 res 为空(添加第一个区间时), 或者前一个已合并好的区间的 末尾 还小于 当前区间的 起始
            // 说明无法合并，直接添加区间
            if (res.empty() || res.back()[1] < L)
                res.push_back({L, R});
            else
                // 合并区间时，是将区间的末尾 修改为 两个区间中的最大范围
                res.back()[1] = max(res.back()[1], R);
        }
        return res;
    }
};