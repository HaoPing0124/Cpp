/*
题意：
    给定一个 9 × 9 的数独棋盘 board，
    判断当前已经填入的数字是否合法。

    只需要验证已经填写的数字，
    不需要判断这个数独最终是否一定有解。

    合法条件：
        1. 每一行数字 1 ~ 9 不能重复；
        2. 每一列数字 1 ~ 9 不能重复；
        3. 每一个 3 × 3 宫内数字 1 ~ 9 不能重复。

    空白位置使用 '.' 表示。

思路：
    使用三个二维布尔数组记录数字是否出现过。

    rows[i][num]：
        表示第 i 行是否已经出现数字 num。

    cols[j][num]：
        表示第 j 列是否已经出现数字 num。

    boxes[k][num]：
        表示第 k 个 3 × 3 宫是否已经出现数字 num。

    遍历整个棋盘：

    如果当前位置是 '.'，
    直接跳过。

    否则将字符转换成数字：
        num = board[i][j] - '0'

    当前格子所在的 3 × 3 宫编号为：
        box = (i / 3) * 3 + j / 3

    如果当前数字已经在对应的行、列或宫中出现过，
    说明数独无效，直接返回 false。

    否则将三个位置标记为 true。

    遍历结束都没有冲突，
    返回 true。

时间复杂度：O(1)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool rows[9][10] = {};
        bool cols[9][10] = {};
        bool boxes[9][10] = {};

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                // 空白格不需要检查
                if (board[i][j] == '.')
                {
                    continue;
                }

                int num = board[i][j] - '0';

                // 当前格子所在的 3 × 3 宫编号
                int box = (i / 3) * 3 + j / 3;

                // 当前数字在对应的行、列或宫中已经出现过
                if (rows[i][num] || cols[j][num] || boxes[box][num])
                {
                    return false;
                }

                // 标记当前数字已经出现
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};