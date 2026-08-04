/*
题意：
    给定二叉树的前序遍历 preorder 和中序遍历 inorder，
    构造并返回原二叉树。

思路：
    前序遍历的顺序是：
        根 -> 左 -> 右

    所以前序数组中当前第一个尚未使用的元素，
    一定是当前子树的根结点。

    中序遍历的顺序是：
        左 -> 根 -> 右

    在中序数组中找到根结点后：
        根左边属于左子树；
        根右边属于右子树。

    使用哈希表保存结点值在 inorder 中的位置，
    避免每次线性查找。

时间复杂度：O(n)
空间复杂度：O(n)
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
    // mp[value] 表示 value 在 inorder 中的位置
    unordered_map<int, int> mp;

    // 当前需要使用的 preorder 下标
    int pos = 0;
    TreeNode *build(vector<int> &preorder, int left, int right)
    {
        // 当前中序区间为空
        if (left > right)
        {
            return nullptr;
        }

        // 前序遍历当前元素就是这棵子树的根
        int rootVal = preorder[pos++];
        TreeNode *root = new TreeNode(rootVal);

        // 找到根结点在中序数组中的位置
        int mid = mp[rootVal];

        // 必须先构造左子树，因为前序顺序是根、左、右
        root->left = build(preorder, left, mid - 1);

        // 再构造右子树
        root->right = build(preorder, mid + 1, right);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};