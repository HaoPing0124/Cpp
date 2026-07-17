/*
题意：
    给定一个 m × n 的二维矩阵 matrix 和目标值 target。
    矩阵中的每一行从左到右升序排列，
    每一列从上到下升序排列。
    判断 target 是否存在于矩阵中。

思路：
    从矩阵的右上角开始搜索。

    右上角元素具有以下特点：
        左边的元素更小；
        下边的元素更大。

    设当前元素为 matrix[row][col]：

        1. 如果当前元素等于 target，直接返回 true；

        2. 如果当前元素大于 target，
           当前列下面的元素只会更大，
           因此 target 不可能出现在当前列，执行 col--；

        3. 如果当前元素小于 target，
           当前行左边的元素只会更小，
           因此 target 不可能出现在当前行，执行 row++。

    当 row 越过最后一行或 col 越过第一列时，
    说明矩阵中不存在 target。

时间复杂度：O(m + n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;

        // 根据升序特性从矩阵右上角开始查找
        while (row < n && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            // 大了说明这一列都大了
            else if (matrix[row][col] > target)
                col--;
            // 小了说明这一行都小了
            else
                row++;
        }
        return false;
    }
};