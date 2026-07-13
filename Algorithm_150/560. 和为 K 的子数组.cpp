/*
题意：
    给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
    子数组是数组中元素的连续非空序列。

思路：
    使用 前缀和 + 哈希表
    前缀和可以记录子串相加的得数，优化时间
    根据 i + j = k 等同于 i - k = j 的思想，只需要查找需要加上 某个数 就可以等于 k
    遍历前缀和数组，每个数字代表到第 i 个位置时，已经记录了所有 0 —— i 位置子串 组合出现的可能(记录到哈希表中)
    如果 pre[i] - k 还不在哈希表中，代表 用以 i 位置(nums[i])结尾的子串 无论怎么组合都不可能相加得到 k
    如果 pre[i] - k 在哈希表中，说明 我用 nums[i] 这个数字 相加 前面某个组合 是可以达到 k 的，那么 count 要相加这个 我需要的组合 的次数

时间复杂度：O(n);
空间复杂度：O(n);
*/

#include "Algorithm_150.h"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 9, 0);
        unordered_map<int, int> mp;

        // 前缀和
        for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + nums[i - 1];        
        
        mp[0] = 1;  // 必须，因为可能正好nums[i] = k, 也就是pre[i] - k = 0
        int count = 0;
        // 遍历前缀和数组
        for(int i = 1; i <= n; ++i)
        {
            // 如果到这个位置 所需要的 数字在 map 中出现(前缀和中出现过)
            // 也就是我使用前面的数字相加 可以得到我需要的数字(加上这个数字我就可以凑成k(因为i + j = k 等价于 i - k = j))
            // j 也就是我需要寻找的数字
            if(mp[pre[i] - k]) count += mp[pre[i] - k]; // 前面有多少个前缀和组合可以凑成我需要的 j 都加上
            mp[pre[i]]++;   // 将前缀和出现过的都放入map
        }
        return count;
    }
};
