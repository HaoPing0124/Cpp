/*
题意：
    给定括号对数 n，
    返回所有由 n 对括号组成的有效括号字符串。

思路：
    使用回溯，记录已经使用的左括号数量 left
    和右括号数量 right。

    当 left < n 时，可以添加左括号；

    当 right < left 时，可以添加右括号，
    保证构造过程中的右括号数量不会超过左括号数量。

    当字符串长度达到 2 * n 时，得到一个完整答案。

时间复杂度：O(Cn × n)，Cn 表示第 n 个卡特兰数
空间复杂度：O(n)，不计算返回结果
*/

#include "Algorithm_150.h"

class Solution
{
private:
    vector<string> res;
    string path;

    void dfs(int n, int left, int right)
    {
        if (path.size() == 2 * n)
        {
            res.push_back(path);
            return;
        }

        if (left < n)
        {
            path.push_back('(');

            dfs(n, left + 1, right);

            path.pop_back();
        }

        if (right < left)
        {
            path.push_back(')');

            dfs(n, left, right + 1);

            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0);

        return res;
    }
};