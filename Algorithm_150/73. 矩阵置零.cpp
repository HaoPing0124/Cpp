/*
题意：
    给你一个 m × n 的矩阵 matrix，如果矩阵中的某个元素为 0，
    就把该元素所在的整行和整列全部设置为 0。
    要求原地修改矩阵，并且额外空间复杂度为 O(1)。

思路：
    如果额外使用两个数组记录哪些行和列需要置零，
    空间复杂度会达到 O(m + n)，不符合题目要求。

    因此使用矩阵的第一行和第一列作为标记区域：

    matrix[i][0] == 0 表示第 i 行需要全部置零；
    matrix[0][j] == 0 表示第 j 列需要全部置零。

    由于第一行和第一列本身也可能原来就存在 0，
    所以使用 first_row_zero 和 first_col_zero 分别记录：
    第一行是否原本包含 0，以及第一列是否原本包含 0。

    具体步骤：
    1. 检查第一行是否包含 0，记录到 first_row_zero；
    2. 检查第一列是否包含 0，记录到 first_col_zero；
    3. 遍历除第一行、第一列以外的内部元素；
       如果 matrix[i][j] == 0，
       就将 matrix[i][0] 和 matrix[0][j] 设置为 0；
    4. 再次遍历内部元素，根据第一行和第一列中的标记执行置零；
    5. 最后根据 first_row_zero 和 first_col_zero，
       决定是否将第一行和第一列全部置零。

    第一行和第一列必须最后处理，
    因为在处理内部元素时，它们还承担着标记作用。

时间复杂度：O(M × N)
    需要遍历矩阵中的所有元素。

空间复杂度：O(1)
    只使用两个 bool 变量，没有创建与矩阵大小相关的额外容器。
*/

#include "Algorithm_150.h"

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        bool first_row = false;
        bool first_col = false;

        // 检查第一行是否有0
        for (int i = 0; i < m; ++i)
        {
            if (matrix[0][i] == 0)
            {
                first_row = true;
                break;
            }
        }

        // 检查第一列是否有0
        for (int i = 0; i < n; ++i)
        {
            if (matrix[i][0] == 0)
            {
                first_col = true;
                break;
            }
        }

        // 遍历除第一行和第一列以外的矩阵
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                // 记录需要置为0的行和列
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 重新遍历开始置0
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // 最后处理第一行的0
        if (first_row)
        {
            for (int i = 0; i < m; ++i)
                matrix[0][i] = 0;
        }

        // 最后处理第一列的0
        if (first_col)
        {
            for (int i = 0; i < n; ++i)
                matrix[i][0] = 0;
        }
    }
};