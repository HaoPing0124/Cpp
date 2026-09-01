/*
题意：
    给定字符串 s 和 t，
    判断 s 是否为 t 的子序列。

    子序列可以通过删除原字符串中的一些字符得到，
    但不能改变剩余字符之间的相对顺序。

思路：
    使用双指针。

    i 指向字符串 s 当前需要匹配的字符，
    j 从左到右遍历字符串 t。

    当：
        s[i] == t[j]

    说明当前字符匹配成功，
    将 i 向后移动一位，
    继续寻找 s 的下一个字符。

    如果字符不同，
    只移动 j，
    继续在 t 后面寻找当前的 s[i]。

    遍历结束后，
    如果 i == s.size()，
    说明 s 中所有字符都按照原顺序在 t 中找到了，
    返回 true；
    否则返回 false。

时间复杂度：O(|t|)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;

        // j 从左到右遍历 t
        for (int j = 0; j < t.size(); ++j)
        {
            // i 必须先判断没有越过 s 的末尾
            if (i < s.size() && s[i] == t[j])
            {
                ++i;
            }
        }

        // s 中所有字符都成功匹配
        return i == s.size();
    }
};