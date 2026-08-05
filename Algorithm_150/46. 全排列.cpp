/*
题意：
    给定一个不含重复数字的数组 nums，
    返回它的所有可能排列。

思路：
    使用回溯。

    path 保存当前正在构造的排列；
    used[i] 表示 nums[i] 是否已经出现在当前排列中。

    每一层都枚举所有没有被使用的元素。
    当 path 的长度等于 nums 的长度时，
    得到一个完整排列并加入答案。

时间复杂度：O(n × n!)
空间复杂度：O(n)，不计算返回结果
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> vis;
    int n = 0;

    void dfs(vector<int> &nums)
    {
        // 满足一个完整排列
        if (path.size() == n)
        {
            // 添加答案
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (vis[i])
            {
                // 已经选择过的数字就跳过
                continue;
            }

            // 做选择
            vis[i] = true;
            path.push_back(nums[i]);

            dfs(nums);

            // 撤销选择
            vis[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        vis = vector<bool>(n, false);

        dfs(nums);
        return res;
    }
};