/*
题意：
    给定两个字符串 s 和 t，
    判断 t 是否是 s 的字母异位词。

    字母异位词要求两个字符串中的字符种类和每种字符出现次数完全相同，
    字符出现的顺序可以不同。

思路：
    使用长度为 26 的数组 cnt 统计每个小写字母出现的次数。

    先遍历字符串 s：
        cnt[s[i] - 'a']++，
        记录每个字符出现的次数。

    再遍历字符串 t：
        cnt[t[i] - 'a']--，
        抵消对应字符出现的次数。

    如果 s 和 t 是字母异位词，
    最终 26 个位置都应该恰好变成 0。

    如果两个字符串长度不同，
    一定不可能是字母异位词，直接返回 false。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        int cnt[26] = {0};

        // 统计 s 中每个字符出现的次数
        for (auto ch : s)
        {
            cnt[ch - 'a']++;
        }

        // 用 t 中的字符抵消 s 中对应字符的次数
        for (auto ch : t)
        {
            cnt[ch - 'a']--;
        }

        // 全部抵消为 0，说明每个字符出现次数完全相同
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};