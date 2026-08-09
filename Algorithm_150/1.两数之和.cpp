/*
题意：
    给定一个整数数组 nums 和一个目标值 target。

    找出数组中两个不同位置的元素，
    使它们的和等于 target。

    返回这两个元素的下标。

    每组数据保证只有一个有效答案，
    同一个元素不能重复使用。


思路：
    使用哈希表优化查找。

    暴力方法需要枚举所有两个元素：

        nums[i] + nums[j] = target

    时间复杂度为 O(n²)。

    优化思路：

        对于当前遍历到的 nums[i]，
        如果存在另一个数字：

            target - nums[i]

        那么两者相加一定等于 target。


    使用 unordered_map 保存：

        数值 -> 下标


    遍历数组时：

        1. 先查询：

           是否已经出现过 target - nums[i]

           如果存在，直接返回答案。


        2. 如果不存在，
           将当前数字和下标加入哈希表。


    注意：
        必须先查询，再插入。

        因为题目要求不能使用同一个元素两次。


时间复杂度：O(n)

空间复杂度：O(n)
*/
#include "Algorithm_150.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 保存已经遍历过的数字以及对应下标
        unordered_map<int, int> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 当前数字需要寻找的另一个数字
            auto it = res.find(target - nums[i]);

            // 如果之前已经出现过 need，说明找到答案
            if (it != res.end())
            {
                return {it->second, i};
            }

            // 当前数字暂时没有匹配对象，记录下来
            res[nums[i]] = i;
        }
        return {};
    }
};
