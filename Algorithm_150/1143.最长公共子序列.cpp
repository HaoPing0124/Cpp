// 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

// 递推
#include "Algorithm_150.h"

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector f(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(s[i] == t[j]) f[i + 1][j + 1] = f[i][j] + 1;
                else f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
            }
        }
        return f[n][m];
    }
};