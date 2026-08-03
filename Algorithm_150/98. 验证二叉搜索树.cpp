/*
题意：
    给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
    有效 二叉搜索树定义如下：
        节点的左子树只包含 严格小于 当前节点的数。
        节点的右子树只包含 严格大于 当前节点的数。
        所有左子树和右子树自身必须也是二叉搜索树。

思路：
    BST要求：
        左子树所有节点 < 当前节点
        右子树所有节点 > 当前节点

    不能只比较左右孩子，
    因为子树中的节点也必须满足范围。

    使用递归维护每个节点允许的最大值和最小值。

时间复杂度：
    O(n)

空间复杂度：
    O(h)
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
    bool check(TreeNode *root, long long leftMax, long long rightMax)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= leftMax || root->val >= rightMax)
        {
            return false;
        }

        return check(root->left, leftMax, root->val) &&
               check(root->right, root->val, rightMax);
    }

    bool isValidBST(TreeNode *root)
    {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};