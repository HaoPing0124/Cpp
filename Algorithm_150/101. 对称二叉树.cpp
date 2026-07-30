/*
题意：
    给定一棵二叉树的根结点 root，
    判断该二叉树是否关于中心轴左右对称。

思路：
    使用递归判断左右子树是否互为镜像。

    对于两个待比较结点 left 和 right：

    1. 如果两个结点都为空，说明当前位置对称，返回 true；

    2. 如果只有一个结点为空，说明结构不对称，返回 false；

    3. 如果两个结点的值不同，返回 false；

    4. 继续交叉比较：
           left 的左子树与 right 的右子树；
           left 的右子树与 right 的左子树。

       只有两组都对称，整棵树才对称。

时间复杂度：O(n)
空间复杂度：O(h)，h 表示二叉树高度，递归调用栈占用空间
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 1. 两个都空：对称；
    // 2. 一个空一个不空：不对称；
    // 3. 值不同：不对称；
    // 4. 左外侧与右外侧比较；
    // 5. 左内侧与右内侧比较。
    bool check(TreeNode* p1, TreeNode* p2)
    {
        // 如果两个节点都为空 则对称
        if(!p1 && !p2) return true;

        // 检查到此处说明一定不是都为空
        // 如果有一个不为空 则不对称
        if(!p1 || !p2) return false;

        return (p1->val == p2->val && check(p1->left, p2->right) && check(p1->right, p2->left));
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};