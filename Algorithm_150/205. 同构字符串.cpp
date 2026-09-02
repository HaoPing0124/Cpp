/*
题意：
    给定两个字符串 s 和 t，
    判断它们是否为同构字符串。

    同构要求：
        s 中的每个字符都必须唯一映射到 t 中的一个字符；

        相同字符必须始终映射到同一个字符；

        不同字符不能映射到同一个字符。

思路：
    使用双向映射。

    mapST 记录：
        s 中字符 -> t 中字符

    mapTS 记录：
        t 中字符 -> s 中字符

    从左到右同时遍历两个字符串。

    对于当前位置 s[i] 和 t[i]：

    如果 s[i] 已经映射过，
    那么它之前映射的字符必须等于 t[i]。

    如果 t[i] 已经被映射过，
    那么它之前对应的字符必须等于 s[i]。

    如果任意一个方向不一致，
    说明无法建立一一对应关系，
    返回 false。

    如果两个字符都没有建立映射，
    就同时记录两个方向的映射关系。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int mapST[256] = {};
        int mapTS[256] = {};

        for (int i = 0; i < s.size(); ++i)
        {
            char a = s[i];
            char b = t[i];

            // 已有映射时必须保持一致
            if (mapST[a] != 0 || mapTS[b] != 0)
            {
                if (mapST[a] != b + 1 || mapTS[b] != a + 1)
                {
                    return false;
                }
            }
            else
            {
                // +1 是为了让 0 表示 还没有建立映射
                mapST[a] = b + 1;
                mapTS[b] = a + 1;
            }
        }

        return true;
    }
};