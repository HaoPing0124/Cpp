/*
题意：
    给定整数数组 nums 和整数 k，
    返回数组中出现频率最高的 k 个元素。

    返回结果的顺序可以任意。

思路：
    使用哈希表 + 桶排序。

    首先使用 unordered_map 统计每个数字出现的次数：
        数字 -> 出现次数

    数组长度为 n，
    一个数字最多只可能出现 n 次，
    因此创建 n + 1 个桶：
        buf[i] 表示所有出现 i 次的数字。

    遍历哈希表，
    将每个数字按照自己的出现次数放入对应的桶中。

    最后从频率最高的 buf[n] 开始向前遍历，
    将桶中的数字依次加入答案，
    当答案数量达到 k 时直接返回。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        // 统计每个数字出现的次数：数字 -> 频率
        unordered_map<int, int> mp;
        for (auto &x : nums)
        {
            mp[x]++;
        }

        // bucket[i] 保存所有出现 i 次的数字
        vector<vector<int>> buf(n + 1);
        for (auto &[x, y] : mp)
        {
            buf[y].push_back(x);
        }

        vector<int> res;

        // 从最高频率开始向低频率寻找
        for (int i = n; i >= 1; --i)
        {
            for (auto &num : buf[i])
            {
                res.push_back(num);

                // 已经找到前 k 个高频元素
                if (res.size() == k)
                {
                    return res;
                }
            }
        }

        return res;
    }
};