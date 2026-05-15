// 输入一棵节点数为n二叉树，判断该二叉树是否是平衡二叉树。
// 在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
// 平衡二叉树(Balanced Binary Tree)，具有以下性质:
//         它是一棵空树或它的左右两个子树的高度差的绝对值不超过1
//         并且左右两个子树都是一棵平衡二叉树。
// 数据范围:n≤100,树上节点的val值满足0≤n≤1000
// 要求:空间复杂度O(1)，时间复杂度0(n)

#include "Algorithm.hpp"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        return dfs(pRoot) != -1;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = dfs(root->left);
        if (left == -1)
            return -1;
        int right = dfs(root->right);
        if (right == -1)
            return -1;
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};