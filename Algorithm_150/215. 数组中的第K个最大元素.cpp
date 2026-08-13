/*
题意：
    给定整数数组 nums 和整数 k，
    返回数组排序后的第 k 个最大元素。

    第 k 个最大元素按照排序后的位置计算，
    重复元素也需要参与排名。

思路：
    使用快速选择 Quickselect。

    第 k 大元素在升序数组中的下标为：
        target = nums.size() - k

    每次在当前区间随机选择一个元素作为 pivot，
    然后进行一次 partition。

    Quickselect。 完成后：
        pivot 左边的元素都小于等于 pivot；
        pivot 右边的元素都大于 pivot；
        pivot 已经处于最终排序后的正确位置。

    得到 pivot 的最终下标 pos 后：
        如果 pos == target，直接返回 nums[pos]；
        如果 pos < target，只需要继续搜索右半部分；
        如果 pos > target，只需要继续搜索左半部分。

    不需要像快速排序一样继续处理左右两个区间，
    因此随机 Quickselect 的期望时间复杂度为 O(n)。

时间复杂度：期望 O(n)，最坏 O(n²)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int quickselect(vector<int> &nums, int left, int right)
    {
        // 随机选择 pivot，降低连续出现极端划分的概率
        int idx = left + rand() % (right - left + 1);
        swap(nums[idx], nums[right]);

        int pivot = nums[right];
        int i = left;

        // 将小于等于 pivot 的元素移动到左边
        for (int j = left; j < right; ++j)
        {
            if (nums[j] < pivot)
            {
                swap(nums[i], nums[j]);
                ++i;
            }
        }

        // 将 pivot 放到最终位置
        swap(nums[i], nums[right]);

        return i;
    }
    
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // 第 k 大对应升序后的下标 n - k
        int target = n - k;

        while (left <= right)
        {
            int pos = quickselect(nums, left, right);

            if (pos == target)
            {
                return nums[pos];
            }
            else if (pos < target)
            {
                // target 在 pivot 右边
                left = pos + 1;
            }
            else
            {
                // target 在 pivot 左边
                right = pos - 1;
            }
        }

        return -1;
    }
};
