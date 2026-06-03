// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

// 滑动窗口 + 哈希表
// 时间复杂度: O(N)
// 空间复杂度：O(1)
#include "Algorithm_150.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int l = 0, r = 0;
        int res = 0;
        
        while(r < n)
        {
            // 如果存在相同的元素 收缩左边界
            while(st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};