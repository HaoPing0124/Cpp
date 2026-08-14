/*
题意：
    给定一个非负整数数组 nums，初始位于下标 0。
    nums[i] 表示从位置 i 最多可以向右跳 nums[i] 步。
    判断是否能够到达数组最后一个下标。

思路：
    贪心。
    使用 maxReach 表示当前能够到达的最远下标。

    从左向右遍历数组：
    如果当前下标 i 大于 maxReach，说明当前位置无法到达，
    后面的所有位置也无法继续通过当前可达区域到达，因此返回 false。

    如果当前位置可以到达，则使用 i + nums[i] 更新 maxReach。
    当 maxReach 已经覆盖最后一个下标时，可以直接返回 true。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 当前下标已经超过可到达的最远位置
            if (i > maxReach)
            {
                return false;
            }

            // 更新目前能够到达的最远位置
            maxReach = max(maxReach, i + nums[i]);

            // 已经能够覆盖最后一个位置
            if (maxReach >= nums.size() - 1)
            {
                return true;
            }
        }

        return true;
    }
};