/*
题意：
    给定一个非负整数数组 nums，
    nums[i] 表示从当前位置 i 最多可以向后跳跃的长度。

    初始位置在下标 0，
    返回到达最后一个位置 n - 1 所需要的最少跳跃次数。

思路：
    使用贪心算法。

    维护当前一次跳跃能够到达的最远范围 end，
    以及在当前范围内下一次跳跃能够到达的最远位置 maxPos。

    遍历数组时，不断更新当前能够覆盖的最远位置：

        maxPos = max(maxPos, i + nums[i])

    当遍历到当前跳跃范围的边界 end 时，
    说明必须进行下一次跳跃。

    此时：
        ans++;
        end = maxPos;

    因为每次都选择当前范围内能够到达最远的位置，
    所以下一次覆盖范围一定最大，可以保证跳跃次数最少。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;

        // 当前一次跳跃能够覆盖的最远边界
        int end = 0;

        // 当前范围内所有位置能够到达的最远位置
        int maxPos = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // 更新下一次跳跃能够到达的最远位置
            maxPos = max(maxPos, i + nums[i]);

            // 到达当前跳跃边界，需要进行下一跳
            if (i == end)
            {
                ans++;
                end = maxPos;
            }
        }

        return ans;
    }
};