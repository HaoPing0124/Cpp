// 给定一个长度为 n 的数组 arr，求它的最长严格上升子序列的长度。
// 所谓子序列，指一个数组删掉一些数（也可以不删）之后，形成的新数组。
// 例如 [1,5,3,7,3] 数组，其子序列有：[1,3,3]、[7] 等。
// 但 [1,6]、[1,3,5] 则不是它的子序列。
// 我们定义一个序列是 严格上升 的，当且仅当该序列不存在两个下标 i 和 j满足 i<j 且 且arr[i]≥arr[j]
// 数据范围： 0≤n≤1000

// 贪心 + 二分
#include "Algorithm.hpp"
class Solution {
public:
    int LIS(vector<int>& arr) {
        int dp[1010] = { 0 };
        int pos = 0;
        for(auto &x : arr)
        {
            // 第一个数字 或 大于最大的数字
            if(pos == 0 || dp[pos] < x)
            {
                dp[++pos] = x;
            }
            else 
            {
                // 说明可以替换数字，二分查找可替换的位置
                int l = 0, r = pos;
                while(l + 1 < r)
                {
                    int mid = (l + r) / 2;
                    if(dp[mid] <= x) l = mid;
                    else r = mid;
                }
                // 因为要插入在可替换下标+1位置，所以是r
                dp[r] = x;
            }
        }
        return pos;
    }
};