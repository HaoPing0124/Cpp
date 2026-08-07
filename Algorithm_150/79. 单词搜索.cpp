/*
题意：
    给定一个二维字符网格 board 和字符串 word，
    判断是否能够通过上下左右相邻的格子组成 word。

    同一个格子在同一条搜索路径中不能重复使用。

思路：
    使用 DFS + 回溯。

    1. 枚举每一个格子作为单词的起点；

    2. dfs(i, j, k) 表示：
       当前位于 board[i][j]，
       尝试匹配 word[k] 以及后面的字符；

    3. 如果当前位置越界，或者当前字符与 word[k] 不匹配，
       当前搜索失败；

    4. 如果已经匹配到 word 最后一个字符，
       说明找到完整单词，返回 true；

    5. 将当前格子临时修改为特殊字符，
       表示当前路径已经使用该格子；

    6. 继续向上下左右四个方向搜索；

    7. 搜索结束后恢复当前格子的原字符，
       让其他搜索路径仍然可以使用它。

时间复杂度：O(m * n * 4^L)
空间复杂度：O(L)

其中：
    n、m 表示网格行数和列数；
    L 表示 word 的长度。
*/

#include "Algorithm_150.h"

class Solution
{
private:
    int n, m;
    bool dfs(vector<vector<char>> &board, const string &word, int i, int j, int k)
    {
        // 越界，或者当前字符无法匹配
        if (i < 0 || i >= n ||
            j < 0 || j >= m ||
            board[i][j] != word[k])
        {
            return false;
        }

        // 当前字符已经是 word 的最后一个字符
        if (k == word.size() - 1)
        {
            return true;
        }

        // 保存当前字符
        char ch = board[i][j];

        // 当前路径已经使用这个格子
        board[i][j] = '#';

        // 搜索上下左右四个方向
        bool found =
            dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i + 1, j, k + 1) ||
            dfs(board, word, i, j - 1, k + 1) ||
            dfs(board, word, i, j + 1, k + 1);

        // 回溯：恢复现场
        board[i][j] = ch;

        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty())
        {
            return false;
        }

        n = board.size();
        m = board[0].size();

        if (word.size() > n * m)
        {
            return false;
        }

        // 枚举所有可能的起点
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};