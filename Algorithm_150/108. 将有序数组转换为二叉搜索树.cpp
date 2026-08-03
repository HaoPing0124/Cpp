/*
题意：
    给定一个升序数组 nums，
    将它转换成一棵高度平衡的二叉搜索树。

思路：
    二叉搜索树满足：
        左子树 < 根节点 < 右子树

    为了保证高度平衡，
    每次选择数组中间位置作为根节点。

    然后递归构造左半部分和右半部分。

时间复杂度：
    O(n)

空间复杂度：
    O(log n)
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
    TreeNode *dfs(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        // 取中间元素作为根节点
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = dfs(nums, left, mid - 1);   // 左半部分构造左子树
        root->right = dfs(nums, mid + 1, right); // 右半部分构造右子树

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1);
    }
};