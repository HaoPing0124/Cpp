// 给你一个字符串 s，找到 s 中最长的 回文 子串。

#include "Algorithm_150.h"

// 中心扩展法
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0, len = 0;
        for(int i = 0; i < n; ++i)
        {
            // 判断奇数回文情况
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            if(right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }

            // 判断偶数回文情况
            left = i;
            right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            if(right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
        }
        return s.substr(begin, len);
    }
};

// 动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        int len = 1, begin = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = i; j < n; ++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                if(dp[i][j] && j - i + 1 > len)
                    len = j - i + 1, begin = i;               
            }
        }
        return s.substr(begin, len);
    }
};