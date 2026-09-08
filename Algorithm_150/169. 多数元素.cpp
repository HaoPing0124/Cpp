/*
题意：
    给定一个大小为 n 的数组 nums，
    返回其中的多数元素。

    多数元素是指出现次数大于 n / 2 的元素，
    题目保证多数元素一定存在。

思路：
    使用 Boyer-Moore 投票算法。

    candidate 表示当前候选的多数元素，
    count 表示当前候选元素的“票数”。

    遍历数组：
        如果 count == 0，
        就把当前元素设为新的 candidate。

        如果当前元素等于 candidate，
        count++。

        否则：
        count--。

    因为多数元素出现次数大于其他所有元素次数总和，
    所以不同元素之间不断抵消后，
    最后剩下的 candidate 一定是多数元素。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0;
        int count = 0;

        for (const auto &num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }

            if (num == candidate)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }

        return candidate;
    }
};