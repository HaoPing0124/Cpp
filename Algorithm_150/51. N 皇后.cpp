/*
题意：
    在 n × n 的棋盘上放置 n 个皇后，
    要求任意两个皇后之间不能互相攻击。

    皇后可以攻击同一行、同一列和同一斜线上的棋子。

    返回所有合法的 N 皇后摆放方案，
    'Q' 表示皇后，'.' 表示空位置。

思路：
    使用回溯。

    按照行从上到下放置皇后，
    每一行只放一个皇后，因此不需要额外判断同行冲突。

    对当前第 row 行，枚举每一列 col，
    判断这一列和两条对角线是否已经存在皇后。

    使用三个数组记录占用情况：
        cols[col]：第 col 列是否已经存在皇后；
        diag1[row - col + n - 1]：主对角线是否被占用；
        diag2[row + col]：副对角线是否被占用。

    如果当前位置没有冲突：
        放置皇后并标记列和两条对角线，
        递归处理下一行。

    递归返回后：
        撤销皇后和对应标记，
        继续尝试当前行的其他列。

    当 row == n 时，
    说明 n 行都成功放置了皇后，
    将当前棋盘加入答案。

时间复杂度：O(n!)，另外保存每个答案需要 O(n²) 的复制开销
空间复杂度：O(n²)，不计算最终返回的答案空间
*/

#include "Algorithm_150.h"

class Solution
{
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;

    void dfs(int row, int n)
    {
        // n 行都成功放置皇后，得到一种合法方案
        if (row == n)
        {
            res.push_back(board);
            return;
        }

        // 尝试在当前 row 行的每一列放置皇后
        for (int col = 0; col < n; ++col)
        {
            // 当前列或两条对角线已经有皇后，不能放
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
            {
                continue;
            }

            // 做选择：当前位置放置皇后
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row - col + n - 1] = true;
            diag2[row + col] = true;

            // 继续处理下一行
            dfs(row + 1, n);

            // 撤销选择，恢复现场
            board[row][col] = '.';
            cols[col] = false;
            diag1[row - col + n - 1] = false;
            diag2[row + col] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        board = vector<string>(n, string(n, '.'));

        cols = vector<bool>(n, false);

        // row - col + n - 1 和 row + col 的范围都是 0 ~ 2n - 2
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        dfs(0, n);

        return res;
    }
};