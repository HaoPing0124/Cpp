/*
题意：
    给定两棵二叉树 root 和 subRoot，
    判断 root 中是否存在一棵子树，与 subRoot 的结构和结点值完全相同。

    root 中的任意一个结点都可以作为子树的根结点，
    但从该结点开始的整棵树必须与 subRoot 完全相同。

思路：
    使用递归，整个过程分成两个问题。

    第一个问题：
        判断以当前 root 结点为根的树，是否与 subRoot 完全相同。

        使用 check 函数同时比较两棵树：

            1. 两个结点都为空，当前位置相同，返回 true；
            2. 只有一个结点为空，结构不同，返回 false；
            3. 两个结点都不为空时，需要满足：
                   当前结点值相同；
                   左子树相同；
                   右子树相同。

    第二个问题：
        如果以当前 root 为根的树与 subRoot 不同，
        就继续在 root 的左子树和右子树中寻找。

        因此：

            isSubtree(root, subRoot)
                = check(root, subRoot)
                || isSubtree(root->left, subRoot)
                || isSubtree(root->right, subRoot)

时间复杂度：O(m × n)
    m 是 root 的结点数量，n 是 subRoot 的结点数量。
    最坏情况下，root 的每个结点都需要调用一次 check，
    每次 check 最多比较 subRoot 的全部 n 个结点。

空间复杂度：O(h1 + h2)
    h1 是 root 的高度，h2 是 subRoot 的高度，
    空间主要来自 isSubtree 和 check 的递归调用栈。
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
    // 判断以 p 和 q 为根的两棵树是否完全相同
    bool check(TreeNode *p, TreeNode *q)
    {
        // 两个结点都为空，说明当前位置结构相同
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        // 只有一个结点为空，说明两棵树结构不同
        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        // 当前结点值、左子树和右子树必须全部相同
        return p->val == q->val && check(p->left, q->left) && check(p->right, q->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // 空树可以看作任意一棵树的子树
        if (subRoot == nullptr)
        {
            return true;
        }

        // root 已经搜索到空结点，仍未找到 subRoot
        if (root == nullptr)
        {
            return false;
        }

        // 尝试把当前 root 结点作为子树根结点进行比较
        if (check(root, subRoot))
        {
            return true;
        }

        // 当前结点不匹配，继续在左右子树中寻找
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};