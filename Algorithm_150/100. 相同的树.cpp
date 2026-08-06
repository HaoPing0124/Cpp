/*
题意：
    给定两棵二叉树的根结点 p 和 q，
    判断这两棵二叉树是否完全相同。

    两棵树完全相同需要同时满足：

        1. 树的结构完全相同；
        2. 对应位置结点的值完全相同。

思路：
    使用递归，同时比较两棵树对应位置的结点。

    对于当前结点 p 和 q，共有三种情况：

        1. p 和 q 都为空：
           说明当前位置的结构相同，返回 true。

        2. p 和 q 中只有一个为空：
           说明两棵树当前位置的结构不同，返回 false。

        3. p 和 q 都不为空：
           需要同时满足：
               p 和 q 的值相同；
               p 和 q 的左子树相同；
               p 和 q 的右子树相同。

    只有以上三个条件全部成立，两棵树才完全相同。

时间复杂度：O(min(m, n))
    m 和 n 分别是两棵树的结点数量。
    最坏情况下两棵树完全相同，需要比较所有结点。

空间复杂度：O(h)
    h 是递归过程中到达的树高。
    平衡二叉树中为 O(log n)，链状二叉树中最坏为 O(n)。
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
    bool check(TreeNode *p, TreeNode *q)
    {
        // 两个结点都为空，说明当前位置的结构相同
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        // 只有一个结点为空，说明两棵树的结构不同
        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        // 当前结点值、左子树和右子树必须全部相同
        return p->val == q->val && check(p->left, q->left) && check(p->right, q->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return check(p, q);
    }
};