/*
题意：
    给定一个 m 行 n 列的矩阵，按照顺时针螺旋顺序，
    返回矩阵中的所有元素。

思路：
    使用 top、bottom、left、right 表示当前还没有遍历的矩形边界。

    每一轮按照以下顺序遍历：
        1. 从左到右遍历上边，然后 top++；
        2. 从上到下遍历右边，然后 right--；
        3. 如果 top <= bottom，从右到左遍历下边，然后 bottom--；
        4. 如果 left <= right，从下到上遍历左边，然后 left++。

    遍历下边和左边之前必须重新判断边界，
    防止矩阵最后只剩一行或一列时重复加入元素。

时间复杂度：O(m * n)
空间复杂度：O(1)，不计算返回结果 res 占用的空间
*/

#include "Algorithm_150.h"
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        vector<int> res;
        while (top <= bottom && left <= right)
        {
            // 遍历上边：从左向右
            for (int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            top++;

            // 遍历右边：从上向下
            for (int i = top; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            right--;

            // 收缩完还不越界再继续遍历
            if (top <= bottom && left <= right)
            {
                // 遍历下边：从右向左
                for (int i = right; i >= left; --i)
                    res.push_back(matrix[bottom][i]);
                bottom--;

                // 遍历左边：从下向上
                for (int i = bottom; i >= top; --i)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};