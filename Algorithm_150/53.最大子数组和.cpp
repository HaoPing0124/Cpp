//53.最大子数组和
//给你一个整数数组 nums
//请你找出一个具有最大和的连续子数组（子数组最少包含一个元素）返回其最大和。
//子数组是数组中的一个连续部分。

#include"Algorithm_150.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int min_pre_sum = 0;
        int pre_sum = 0;
        for (int x : nums) {
            pre_sum += x;                            // 当前的前缀和
            ans = max(ans, pre_sum - min_pre_sum);   // 减去前缀和的最小值
            min_pre_sum = min(min_pre_sum, pre_sum); // 维护前缀和的最小值
        }
        return ans;
    }
};
