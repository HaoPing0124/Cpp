/*
题意：
    给定一个非递减排列的整数数组 nums，
    原地删除部分重复元素，
    使每个元素最多出现两次，
    返回处理后数组的新长度。

思路：
    使用双指针。

    slow 表示下一个有效元素应该写入的位置，
    fast 表示当前正在检查的位置。

    前两个元素无论是否相同都可以直接保留，
    所以 slow 从 2 开始。

    对于 nums[fast]，
    只需要判断它是否等于当前有效数组倒数第 2 个元素 nums[slow - 2]。

    如果：
        nums[fast] != nums[slow - 2]

    说明当前数字在有效数组中还没有出现两次，
    可以保留，将它写到 nums[slow]，然后 slow++。

    如果：
        nums[fast] == nums[slow - 2]

    由于数组有序，
    说明当前数字已经至少出现了两次，
    当前元素不能继续保留，直接跳过。

    最终 slow 就是处理后的有效数组长度。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        // 长度不超过 2 时，所有元素都可以直接保留
        if (n <= 2)
        {
            return n;
        }

        // slow 表示下一个有效元素应该写入的位置
        int slow = 2;

        // fast 从第 3 个元素开始检查
        for (int fast = 2; fast < n; ++fast)
        {
            // 和有效数组倒数第 2 个元素不同，说明当前元素还能保留
            if (nums[fast] != nums[slow - 2])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
        }

        return slow;
    }
};