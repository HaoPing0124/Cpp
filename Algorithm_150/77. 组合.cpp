/*
题意：
    给定两个整数 n 和 k，
    返回范围 [1, n] 中所有可能的 k 个数的组合。

思路：
    使用回溯。

    path 记录当前已经选择的数字，
    res 记录最终所有组合。

    backtracking(start) 表示：
        从 start 开始继续选择数字。

    每次从 start 遍历到 n，
    选择当前数字 i 加入 path，
    然后递归从 i + 1 开始继续选择，
    保证每个数字只使用一次，
    同时避免产生 [1,2] 和 [2,1] 这样的重复组合。

    当 path.size() == k 时，
    说明已经选够 k 个数字，
    将当前 path 加入结果并返回。

时间复杂度：O(C(n,k) * k)
空间复杂度：O(k)，不计算返回结果
*/

#include "Algorithm_150.h"

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(int n, int k, int start)
    {
        // 已经选择 k 个数字，得到一个合法组合
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            // 做选择
            path.push_back(i);

            // 下一层从 i + 1 开始，避免重复选择
            backtracking(n, k, i + 1);

            // 撤销选择
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return res;
    }
};