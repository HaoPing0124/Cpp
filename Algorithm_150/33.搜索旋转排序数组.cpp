/*
题意：
    给定一个按升序排列但经过旋转的互异整数数组 nums 和目标值 target，
    在 O(log n) 时间复杂度内寻找 target 的下标，若不存在则返回 -1。

思路：
    采用双指针（开区间 (l, r)）的二分查找：
    1. 计算 mid，若 nums[mid] == target 则直接返回下标。
    2. 若 nums[0] <= nums[mid]，说明左半段递增：
       - 若 target 在 [nums[0], nums[mid]) 范围内，更新 r = mid，否则更新 l = mid。
    3. 否则说明右半段递增：
       - 若 target 在 (nums[mid], nums[r-1]] 范围内，更新 l = mid，否则更新 r = mid。
    4. 循环结束未找到则返回 -1。

时间复杂度：O(log n)
空间复杂度：O(1)
*/

#include"Algorithm_150.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;
        int mid = 0;
        while (l + 1 < r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid])
            {
                if (target < nums[mid] && target >= nums[0])
                    r = mid;
                else l = mid;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r - 1])
                    l = mid;
                else r = mid;
            }

        }
        return -1;
    }
};