/*
题意：
    给定一个升序数组 nums 和目标值 target。

    如果 target 存在，返回其下标；
    如果 target 不存在，返回其按升序插入的位置。

思路：
    使用二分查找寻找第一个大于等于 target 的位置。

    left 初始化为 -1，表示虚拟的“小于 target”区域；
    right 初始化为 n，表示虚拟的“大于等于 target”区域。

    如果 nums[mid] < target，
    说明 mid 属于左侧区域，令 left = mid；

    否则 nums[mid] >= target，
    说明 mid 可能是答案，令 right = mid。

    循环结束后，right 就是第一个大于等于 target 的位置。

时间复杂度：O(log n)
空间复杂度：O(1)
*/

#include"Algorithm_150.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = -1, right = nums.size();

        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid;
            else right = mid;
        }

        // 将插入的位置(第一个大于等于 left 的位置)
        return right;   // 或 left + 1
    }
};