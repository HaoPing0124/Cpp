/*
题意：
    给定一棵二叉树和目标值 targetSum，
    统计结点值之和等于 targetSum 的向下路径数量。

    路径不一定从根结点开始，也不一定在叶子结点结束，
    但必须沿父结点到子结点的方向连续向下。

思路：
    使用前缀和与哈希表。

    curSum 表示从根结点到当前结点的路径和。

    如果以前出现过前缀和：
        curSum - targetSum

    那么从该位置之后到当前结点之间的路径和，
    就等于 targetSum。

    哈希表 cnt 保存当前递归路径中，
    每个前缀和出现的次数。

    递归离开当前结点时必须执行回溯，
    删除当前前缀和，防止影响其他分支。

时间复杂度：O(n)
空间复杂度：O(h)
*/

#include "Algorithm_150.h"

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<long long, int> mp;
    int target = 0;

    int dfs(TreeNode *root, long long curSum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        curSum += root->val;

        // 以当前结点作为终点的合法路径数量
        int res = mp[curSum - target];

        // 当前前缀和进入当前递归路径
        mp[curSum]++;

        res += dfs(root->left, curSum);
        res += dfs(root->right, curSum);

        // 回溯：离开当前结点，删除当前前缀和
        mp[curSum]--;

        return res;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        mp[0] = 1; // 剩余 0 就可以达到targetSum 所以是 1
        target = targetSum;

        return dfs(root, 0);
    }
};