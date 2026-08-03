/*
题意：
    给定一个二叉搜索树的根节点 root ，和一个整数 k
    请你设计一个算法查找其中第 k 小的元素（k 从 1 开始计数）。

思路：
    二叉搜索树的中序遍历结果是升序数组。

    因此：
        中序遍历第 k 个节点
        就是第 k 小元素。

    使用计数变量 cnt，
    不保存整个遍历结果，
    找到第 k 个节点立即返回。

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
    int cnt = 0;
    int res = 0;

    void dfs(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return;
        }

        // 访问左子树
        dfs(root->left, k);

        // 如果已经找到，不继续
        if (cnt >= k)
        {
            return;
        }

        // 访问当前节点
        cnt++;

        if (cnt == k)
        {
            res = root->val;
            return;
        }

        // 访问右子树
        dfs(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return res;
    }
};