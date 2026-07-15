/*
题意：
    给你一个整数数组 nums，返回数组 answer，
    其中 answer[i] 等于 nums 中除了 nums[i] 以外，其余所有元素的乘积。
    要求不能使用除法，并且时间复杂度为 O(n)。
    注：输出数组不算作额外空间

思路：
    对于位置 i 来说，除了 nums[i] 自身以外的元素乘积，可以拆成两部分：
        answer[i] = nums[i] 左边所有元素的乘积 × nums[i] 右边所有元素的乘积

    第一次从右向左遍历：
        使用 pre[i] 保存 nums[i] 右边所有元素的乘积。
        比如 nums = [1, 2, 3, 4]：
            pre[0] = 2 × 3 × 4 = 24
            pre[1] = 3 × 4 = 12
            pre[2] = 4
            pre[3] = 1

    第二次从左向右遍历：
        使用 ans 保存当前位置左边所有元素的乘积。
        将 pre[i] 乘上 ans，就得到了除 nums[i] 自身以外的所有元素乘积。

        每处理完一个位置，再执行：
            ans *= nums[i]
        让 ans 继续记录下一个位置左边所有元素的乘积。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        // 第一次遍历后，pre[i] 保存 nums[i] 右边所有元素的乘积
        vector<int> pre(n, 1);

        // 从右向左计算每个位置右边所有元素的乘积
        // 最后一个位置右边没有元素，所以 pre[n - 1] 保持为 1
        for (int i = n - 2; i >= 0; --i)
        {
            // pre[i + 1] 是 nums[i + 1] 右边所有元素的乘积
            // 再乘上 nums[i + 1]，就得到 nums[i] 右边所有元素的乘积
            pre[i] = pre[i + 1] * nums[i + 1];
        }

        // ans 保存当前位置左边所有元素的乘积
        // 第 0 个位置左边没有元素，所以初始值为 1
        int ans = 1;

        // 从左向右计算每个位置左边所有元素的乘积
        for (int i = 0; i < n; ++i)
        {
            // pre[i] 原本保存右边所有元素的乘积
            // 乘上 ans 保存的左边所有元素的乘积
            // 就得到除了 nums[i] 自身以外，其余所有元素的乘积
            pre[i] *= ans;

            // 将当前元素乘入 ans
            // 使 ans 在下一轮表示下一个位置左边所有元素的乘积
            ans *= nums[i];
        }

        return pre;
    }
};