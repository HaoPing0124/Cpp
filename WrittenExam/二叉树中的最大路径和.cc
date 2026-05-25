// 二叉树里面的路径被定义为:从该树的任意节点出发
// 经过父=>子或者子=>父的连接，达到任意节点的序列。
// 注意:
//     1.同一个节点在一条二叉树路径里中最多出现一次
//     2.一条路径至少包含一个节点，且不一定经过根节点
// 给定一个二叉树的根节点root，请你计算它的最大路径和


#include "Algorithm.hpp"
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int res = -1010;
    int dfs(TreeNode* root)
    {
        if(!root) return 0;

        int l = max(0, dfs(root->left));    // 左子树最大单链和
        int r = max(0, dfs(root->right));   // 右子树最大单链和

        res = max(res, root->val + (l + r));
        
        // 只返回最大的单链和，返回到上一层判断
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};