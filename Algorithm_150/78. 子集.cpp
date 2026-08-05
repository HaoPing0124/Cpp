/*
题意：
    给定一个元素互不相同的整数数组 nums，
    返回它的所有子集。

思路：
    使用回溯。

    path 保存当前子集；
    start 表示本层可以从哪个位置开始选择。

    因为子集不考虑顺序，所以选择 nums[i] 后，
    下一层只能从 i + 1 开始，防止生成重复子集。

    搜索树中的每个结点都是一个合法子集，
    因此每次进入 dfs 都要收集 path。

时间复杂度：O(n × 2^n)
空间复杂度：O(n)，不计算返回结果
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &nums, int start)
    {
        // 每个状态都是一个合法子集
        res.push_back(path);

        for (int i = start; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);

            dfs(nums, i + 1);

            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};