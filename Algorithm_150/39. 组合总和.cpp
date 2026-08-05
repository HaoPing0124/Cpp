/*
题意：
    给定一个无重复元素的正整数数组 candidates
    和目标值 target，返回所有和为 target 的组合。

    每个候选数字可以被重复选择。

思路：
    回溯 / 排序
    回溯法搜索组合，排序辅助剪枝优化

    remain 表示还需要凑出的数值；
    start 表示本层从哪个位置开始选择。

    组合不考虑顺序，因此只能从 start 向后选择。
    当前元素允许重复使用，因此递归时仍然传入 i。

    先对数组排序。如果 candidates[i] > remain，
    后续元素也一定无法选择，可以直接停止本层搜索。

时间复杂度：O(n^target / min(candidates))
空间复杂度：O(target / min(Candidate))
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    int n = 0;

    void dfs(vector<int> &candidates, int target, int start)
    {
        // target 刚好为 0 才是正确组合
        if (target == 0)
        {
            res.push_back(path);
            return;
        }

        // start 之前的已经选过
        for (int i = start; i < n; ++i)
        {
            // 剪枝
            // 升序数组中 选取的数字 已经大于了 需要的数字
            // 说明后面的数字不可能再满足条件了
            if (candidates[i] > target)
            {
                break;
            }

            path.push_back(candidates[i]);

            // 传入 i，表示当前数字还可以继续使用
            dfs(candidates, target - candidates[i], i);

            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        n = candidates.size();

        // 排序方便剪枝
        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0);
        return res;
    }
};