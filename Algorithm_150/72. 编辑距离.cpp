/*
题意：
    给定两个字符串 word1 和 word2，
    可以对 word1 进行插入、删除、替换三种操作，
    求将 word1 转换成 word2 所需要的最少操作次数。

思路：
    使用二维动态规划。

    定义：
        dp[i][j] 表示将 word1 的前 i 个字符，
        转换成 word2 的前 j 个字符所需要的最少操作次数。

    初始化：
        dp[i][0] = i
        表示将 word1 的前 i 个字符变成空字符串，
        需要删除 i 次。

        dp[0][j] = j
        表示将空字符串变成 word2 的前 j 个字符，
        需要插入 j 次。

    计算 dp[i][j] 时：

    如果：
        word1[i - 1] == word2[j - 1]

    说明当前两个字符相同，不需要额外操作：
        dp[i][j] = dp[i - 1][j - 1]

    如果当前两个字符不同，有三种操作：

        1. 删除 word1 当前字符：
            dp[i - 1][j] + 1

        2. 插入一个字符：
            dp[i][j - 1] + 1

        3. 将 word1 当前字符替换成 word2 当前字符：
            dp[i - 1][j - 1] + 1

    三种操作取最小值。

时间复杂度：O(m × n)
空间复杂度：O(m × n)
*/

#include"Algorithm_150.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j] 表示 word1 前 i 个字符转换成 word2 前 j 个字符的最少操作次数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // word1 前 i 个字符转换为空字符串，需要删除 i 次
        for(int i = 0; i <= m; ++i)
        {
            dp[i][0] = i;
        }

        // 空字符串转换成 word2 前 j 个字符，需要插入 j 次
        for(int j = 0; j <= n; ++j)
        {
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                // 当前字符相同，不需要额外操作
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 删除 word1 当前字符
                    int del = dp[i - 1][j] + 1;

                    // 给 word1 插入一个字符
                    int insert = dp[i][j - 1] + 1;

                    // 替换 word1 当前字符
                    int replace = dp[i - 1][j - 1] + 1;

                    dp[i][j] = min(del, min(insert, replace));
                }
            }
        }

        return dp[m][n];
    }
};