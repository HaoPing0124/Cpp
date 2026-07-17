/*
题意：
    给定一个 n × n 的二维矩阵 matrix，将矩阵顺时针旋转 90 度。
    必须直接修改原矩阵，不能使用另一个二维矩阵保存结果。

思路：
    顺时针旋转 90 度可以分成两步：

    1. 沿主对角线转置矩阵。
       将 matrix[i][j] 和 matrix[j][i] 交换。

    2. 将转置后的每一行进行反转。

    例如：
        原矩阵：
            1 2 3
            4 5 6
            7 8 9

        转置后：
            1 4 7
            2 5 8
            3 6 9

        每行反转后：
            7 4 1
            8 5 2
            9 6 3

时间复杂度：O(n²)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // 沿对角线交换
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto &row : matrix)
        {
            // 翻转每一行
            reverse(row.begin(), row.end());
        }
    }
};