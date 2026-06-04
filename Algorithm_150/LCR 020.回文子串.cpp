// 给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

// 动态规划
#include "Algorithm_150.h"

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        int res = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = i; j < n; ++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;

                if(dp[i][j]) res++;
            }
        }
        return res;
    }
};