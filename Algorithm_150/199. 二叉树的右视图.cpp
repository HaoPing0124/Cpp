/*
题意：
    给定一个二叉树的 根节点 root，想象自己站在它的右侧
    按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

思路：
    使用 BFS 层序遍历。

    每次先记录当前层的结点数量 sz，
    然后从左到右遍历当前层。

    当前层最后访问到的结点，
    就是这一层最右边的结点，将其加入答案。

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
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();

                // 当前层最后一个结点就是右视图结点
                if (i == sz - 1)
                {
                    res.push_back(cur->val);
                }

                // 当前结点的左孩子存在才入队
                if (cur->left)
                {
                    q.push(cur->left);
                }

                // 当前结点的右孩子存在才入队
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }

        return res;
    }
};