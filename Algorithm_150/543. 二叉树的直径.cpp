/*
题意：
    给你一棵二叉树的根节点，返回该树的 直径 。
    二叉树的 直径 是指树中任意两个节点之间最长路径的 长度。
    这条路径可能经过也可能不经过根节点 root 。
    两节点之间路径的 长度 由它们之间边数表示。

思路：
    使用后序遍历计算每个结点的左右子树最大深度。

    对于当前结点 root：

        1. 递归计算左子树最大深度 leftDepth；
        2. 递归计算右子树最大深度 rightDepth；
        3. 经过当前结点的最长路径长度为：
               leftDepth + rightDepth
        4. 使用 res 记录所有结点能够形成的最大路径；
        5. 向父结点返回当前结点向下的最大深度：
               max(leftDepth, rightDepth) + 1

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
    int res = 0;

public:
    int depth(TreeNode *root)
    {
        // 节点为空返回
        if (!root)
        {
            return 0;
        }

        // 递归获取从当前节点看 左右子树的最大深度
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        // 更新全局最大值:当前最大值 对比 经过该节点的左子树和右子树最深深度
        res = max(res, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        depth(root);
        return res;
    }
};