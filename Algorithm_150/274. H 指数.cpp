/*
题意：
    给定整数数组 citations，
    citations[i] 表示第 i 篇论文被引用的次数，
    返回研究者最大的 h 指数。

    h 指数表示：
    至少有 h 篇论文的引用次数大于等于 h。

思路：
    使用计数桶。

    一共有 n 篇论文，
    所以 h 指数最大不可能超过 n。

    创建 bucket，
    bucket[i] 表示引用次数为 i 的论文数量。

    对于引用次数大于等于 n 的论文，
    统一放入 bucket[n]，
    因为这些论文对于判断 h <= n 来说效果完全相同。

    从 n 开始向 0 倒序遍历，
    使用 cnt 统计引用次数大于等于当前 h 的论文数量。

    当：
        cnt >= h

    说明至少有 h 篇论文的引用次数大于等于 h，
    当前 h 就是最大的合法 h 指数，直接返回。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include"Algorithm_150.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        // bucket[i] 表示引用次数为 i 的论文数量
        // 引用次数 >= n 的论文统一放入 bucket[n]
        vector<int> bucket(n + 1);

        for(const auto &x : citations)
        {
            if(x >= n)
            {
                ++bucket[n];
            }
            else
            {
                ++bucket[x];
            }
        }

        // cnt 表示引用次数 >= h 的论文数量
        int cnt = 0;

        for(int h = n; h >= 0; --h)
        {
            cnt += bucket[h];

            // 至少有 h 篇论文引用次数 >= h
            if(cnt >= h)
            {
                return h;
            }
        }

        return 0;
    }
};