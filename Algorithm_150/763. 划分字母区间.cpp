/*
题意：
    给定字符串 s，
    将字符串划分成尽可能多的片段。

    要求：
        同一个字母最多只能出现在一个片段中。

    返回每个片段的长度。

思路：
    使用贪心算法。

    先统计每个字符最后一次出现的位置。

    遍历字符串，维护当前片段的范围：

        start：
            当前片段开始位置。

        end：
            当前片段必须达到的最远位置。

    遍历过程中：
        每遇到一个字符，
        更新当前片段结束位置：

            end = max(end, last[s[i]])

        当当前位置 i 到达 end 时，
        说明当前片段已经包含了其中所有字符的最后出现位置，
        可以安全划分。

    将当前片段长度加入答案，
    并开始新的片段。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res;

        // 记录每个字符最后一次出现的位置
        vector<int> last(26);

        for (int i = 0; i < s.size(); ++i)
        {
            last[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            // 当前片段必须覆盖当前字符最后出现的位置
            end = max(end, last[s[i] - 'a']);

            // 到达片段最远位置，可以切割
            if (i == end)
            {
                res.push_back(i - start + 1);

                start = i + 1;
            }
        }

        return res;
    }
};