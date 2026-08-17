/*
题意：
    给定字符串 s 和字符串列表 wordDict，
    判断 s 是否可以由字典中的一个或多个单词拼接得到。

    字典中的单词可以重复使用。

思路：
    使用动态规划。

    定义：
        f[i] 表示字符串 s 的前 i 个字符能否由字典中的单词组成。

    初始化：
        f[0] = true

    计算 f[i] 时枚举最后一个单词的起始位置 j。

    字符串被分成：
        s[0 ... j - 1]
        s[j ... i - 1]

    如果前 j 个字符能够成功拆分，
    并且 s[j ... i - 1] 在字典中，
    那么前 i 个字符也能够成功拆分。

    状态转移：
        f[i] = f[j] && s[j ... i - 1] 在字典中

    使用 unordered_set 保存字典，
    方便快速判断单词是否存在。

时间复杂度：O(n² × L)
空间复杂度：O(n + m)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        // f[i] 表示前 i 个字符能否成功拆分
        vector<bool> f(n, false);

        // 空字符串认为已经成功拆分
        f[0] = true;

        // 依次计算前 1、2、3 ... n 个字符能否拆分
        for (int i = 1; i <= n; ++i)
        {
            // j 表示最后一个单词的起始位置
            for (int j = 0; j < i; ++j)
            {
                // 前 j 个字符可以拆分，
                // 并且 s[j ... i-1] 是字典中的单词
                if (f[j] && st.count(s.substr(j, i - j)))
                {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[n];
    }
};