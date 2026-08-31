/*
题意：
    给定一个罗马数字字符串 s，
    将其转换为对应的整数。

思路：
    使用哈希表记录每个罗马字符对应的数值。

    从左到右遍历字符串。

    如果当前字符表示的数值小于右边字符表示的数值，
    说明当前字符属于特殊减法情况，
    例如：
        IV = 5 - 1
        IX = 10 - 1
        XL = 50 - 10

    此时将当前值减去。

    否则当前字符正常累加。

    最后一个字符右边没有字符，
    直接加到答案中。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int res = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            // 当前值比右边小，属于减法情况
            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]])
            {
                res -= mp[s[i]];
            }
            else
            {
                res += mp[s[i]];
            }
        }

        return res;
    }
};