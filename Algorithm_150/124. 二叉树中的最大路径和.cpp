/*
题意：
    给定一棵二叉树，返回其中任意一条路径的最大路径和。

    路径至少包含一个结点，不一定经过根结点，
    并且同一个结点在一条路径中最多出现一次。

思路：
    使用后序遍历。

    dfs(root) 返回：
        从当前结点 root 出发，只向下选择一个方向时，
        能够得到的最大路径贡献。

    对于当前结点：

        1. 递归得到左右子树的最大贡献；
        2. 如果某一侧贡献为负数，就不选择该侧，按 0 处理；
        3. 经过当前结点的完整路径和为：
               leftGain + root->val + rightGain
           使用它更新全局最大值；
        4. 向父结点返回时不能同时选择左右两边，
           只能选择贡献更大的一侧：
               root->val + max(leftGain, rightGain)

时间复杂度：O(n)
空间复杂度：O(h)，h 表示二叉树高度
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
    int res = INT_MIN;

    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // 负贡献不选择，按 0 处理
        int leftMax = max(0, dfs(root->left));
        int rightMax = max(0, dfs(root->right));

        // 经过当前结点的完整路径可以同时连接左右两边
        int curPath = leftMax + root->val + rightMax;

        // 更新整棵树的最大路径和
        res = max(res, curPath);

        // 向父结点返回时，只能选择左右一边
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};