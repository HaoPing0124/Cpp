/*
题意：
    给定一棵普通二叉树中的两个结点 p 和 q，
    返回它们的最近公共祖先。

    一个结点可以是它自己的祖先。

思路：
    使用递归搜索左右子树。

    1. 如果 root 为空，返回 nullptr；

    2. 如果 root 等于 p 或 q，
       说明当前结点已经找到，直接返回 root；

    3. 分别递归搜索左右子树；

    4. 如果左右子树都返回非空：
       说明 p 和 q 分别位于当前结点两侧，
       当前结点就是最近公共祖先；

    5. 如果只有一侧非空，
       将该侧结果向上返回。

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
        {
            return root;
        }

        return left ? left : right;
    }
};