// 给定一个长度为n的数组arr，返回arr的最长无重复元素子数组的长度，
// 无重复指的是所有数字都不相同。
// 子数组是连续的，比如[1,3,5,7,9]的子数组有[1,3],[3,5,7]等等，但是[1,3,7]不是子数组

// 哈希表 + 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include "Algorithm.hpp"
class Solution
{
public:
    unordered_map<int, int> mp;
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();
        int l = 0, r = 0;
        int mx = 0;

        while (r < n)
        {
            mp[arr[r]]++; // 进窗口
            while (mp[arr[r]] > 1)
            {                       // 判断
                l = mp[arr[r]] + 1; // 出窗口
            }
            mx = max(mx, r - l + 1); // 更新结果
            r++;
        }
        return mx;
    }
};