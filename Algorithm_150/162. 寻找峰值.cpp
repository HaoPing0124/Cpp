/*
题意：
    给定整数数组 nums，找到任意一个峰值元素并返回其下标。

    峰值元素要求严格大于左右相邻元素，
    并且可以认为数组两侧 nums[-1] 和 nums[n] 都是负无穷。

思路：
    使用二分查找。

    比较 nums[mid] 和 nums[mid + 1]：

    如果 nums[mid] > nums[mid + 1]，
    说明当前位置处于下降趋势，
    那么 mid 左边包括 mid 自身一定存在峰值，
    所以令 right = mid。

    如果 nums[mid] < nums[mid + 1]，
    说明当前位置处于上升趋势，
    那么 mid 右边一定存在峰值，
    所以令 left = mid。

    使用开区间写法：
        left = -1
        right = n - 1

    最终 left + 1 == right，
    right 就是一个峰值下标。

时间复杂度：O(log n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = -1;
        int right = nums.size() - 1;

        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        return right;
    }
};