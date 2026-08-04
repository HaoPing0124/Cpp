/*
题意：
    给定一棵二叉树，将其原地展开成一条单链表。

    展开后：
        1. 每个结点的 left 指针都为 nullptr；
        2. right 指针指向链表中的下一个结点；
        3. 结点顺序与二叉树的先序遍历顺序相同。

思路：
    从根结点开始依次处理每个结点。

    如果当前结点 cur 存在左子树：

        1. 找到左子树中最右边的结点 pre；
        2. 将当前结点原来的右子树接到 pre->right；
        3. 将当前左子树移动到右子树位置；
        4. 将 cur->left 置为 nullptr。

    然后继续处理 cur->right。

时间复杂度：O(n)
空间复杂度：O(1)
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
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                // 找到当前左子树中最右边的结点
                TreeNode *pre = cur->left;
                while (pre->right != nullptr)
                {
                    pre = pre->right;
                }

                // 将原来的右子树接到左子树最右结点后面
                pre->right = cur->right;

                // 将左子树移动到右边
                cur->right = cur->left;

                // 展开后的左指针必须为空
                cur->left = nullptr;
            }

            // 继续处理链表中的下一个结点
            cur = cur->right;
        }
    }
};