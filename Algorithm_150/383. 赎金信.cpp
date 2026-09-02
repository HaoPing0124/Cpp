/*
题意：
    给定两个字符串 ransomNote 和 magazine，
    判断能否使用 magazine 中的字符组成 ransomNote。

    magazine 中的每个字符最多只能使用一次。

思路：
    使用计数数组。

    创建长度为 26 的 cnt 数组，
    cnt[i] 表示 magazine 中对应字母还剩多少个可以使用。

    先遍历 magazine，
    统计每个字符出现的次数。

    再遍历 ransomNote，
    每需要一个字符，
    就将对应字符数量减 1。

    如果减完后小于 0，
    说明 ransomNote 需要的这个字符数量超过了 magazine 能提供的数量，
    直接返回 false。

    如果所有字符都能够成功使用，
    返回 true。

时间复杂度：O(m + n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int cnt[26] = {};

        // 统计 magazine 中每个字符可以使用的数量
        for (const auto &ch : magazine)
        {
            ++cnt[ch - 'a'];
        }

        // ransomNote 每使用一个字符，就消耗一次对应数量
        for (const auto &ch : ransomNote)
        {
            --cnt[ch - 'a'];

            // 当前字符已经不够使用
            if (cnt[ch - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};