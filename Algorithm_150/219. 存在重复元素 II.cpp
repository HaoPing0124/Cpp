/*
题意：
    给定整数数组 nums 和整数 k，
    判断是否存在两个不同下标 i 和 j，
    满足 nums[i] == nums[j]，
    并且 abs(i - j) <= k。

思路：
    使用哈希表记录每个数字最近一次出现的下标。

    从左到右遍历 nums。

    如果当前数字 nums[i] 之前出现过，
    就计算当前位置 i 和它上一次出现位置之间的距离。

    如果距离 <= k，
    说明找到满足条件的两个重复元素，返回 true。

    否则更新当前数字最近一次出现的位置为 i，
    继续向后遍历。

    如果遍历结束都没有找到，返回 false。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k)
            {
                return true;
            }

            // 更新 nums[i] 最近一次出现的位置
            mp[nums[i]] = i;
        }

        return false;
    }
};