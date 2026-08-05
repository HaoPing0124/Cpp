/*
题意：
    给定一个只包含数字 2 到 9 的字符串 digits，
    返回它在电话按键上能够表示的所有字母组合。

思路：
    使用回溯。

    idx 表示当前正在处理 digits 的第几个数字。
    当前层从该数字对应的所有字母中选择一个，
    加入 path 后继续处理下一个数字。

    当 idx 等于 digits.size() 时，
    说明每个数字都已经选择了一个字母，
    将 path 加入答案。

时间复杂度：O(n × n)
空间复杂度：O(n)，不计算返回结果
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<string> res;
    string path;
    string mp[10] = {"", "", "abc", "def", "ghi",
                     "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n = 0;

    void dfs(string digits, int idx)
    {
        // 已选满
        if (idx == n)
        {
            res.push_back(path);
            return;
        }

        // 选取 digits 中的第 idx 个电话号码按键
        // str 存储第 idx 个按键的字母
        string str = mp[digits[idx] - '0'];

        for (auto &ch : str)
        {
            path.push_back(ch);

            dfs(digits, idx + 1);

            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        n = digits.size();
        if (n == 0) return {};

        dfs(digits, 0);
        return res;
    }
};