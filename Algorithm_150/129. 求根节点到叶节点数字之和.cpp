/*
题意：
    给定一棵二叉树，
    每个节点存放一个 0 到 9 的数字。

    每条从根节点到叶子节点的路径都可以组成一个整数，
    求所有这些整数的总和。

思路：
    使用 DFS。

    sum 表示从根节点走到当前节点之前，
    已经组成的数字。

    到达当前节点时：
        sum = sum * 10 + root->val

    例如：
        当前已经是 12，
        再走到节点 3，
        就得到：
        12 * 10 + 3 = 123

    如果当前节点是叶子节点，
    说明已经得到一条完整路径对应的数字，
    直接返回 sum。

    如果不是叶子节点，
    就分别递归左右子树，
    最后将左右结果相加。

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
private:
    int dfs(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // 将当前节点拼到已有数字后面
        sum = sum * 10 + root->val;

        // 叶子节点：得到一条完整的根到叶路径数字
        if (root->left == nullptr && root->right == nullptr)
        {
            return sum;
        }

        return dfs(root->left, sum) + dfs(root->right, sum);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};