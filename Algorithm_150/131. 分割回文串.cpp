/*
题意：
    给定字符串 s，将它分割成若干子串，
    要求每个子串都是回文串，
    返回所有可能的分割方案。

思路：
    使用回溯。

    start 表示当前还没有被分割部分的起始位置。

    枚举 end，从 s[start...end] 中选择一个子串。
    如果该子串不是回文串，跳过；
    如果是回文串，将其加入 path，
    然后从 end + 1 继续分割。

    当 start 等于 s.size() 时，
    说明整个字符串已经分割完成。

时间复杂度：O(n × 2^n)
空间复杂度：O(n)，不计算返回结果
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalin(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }

    void dfs(string s, int start)
    {
        // start 指遍历到字符串 s 的第 start 位置
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i)
        {
            // 判断选择 s[i] 后能否回文
            if (!isPalin(s, start, i))
            {
                continue;
            }

            path.push_back(s.substr(start, i - start + 1));

            dfs(s, i + 1);

            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        dfs(s, 0);

        return res;
    }
};