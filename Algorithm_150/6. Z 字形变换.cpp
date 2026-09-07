/*
题意：
    给定字符串 s 和行数 numRows，
    按照 Z 字形从上到下、再斜向上排列字符，
    最后按照从第一行到最后一行的顺序拼接字符串。

思路：
    使用 vector<string> rows 保存每一行的字符。

    curRow 表示当前字符应该放在哪一行，
    direction 表示当前移动方向：
        1  表示向下移动；
       -1  表示向上移动。

    遍历字符串中的每个字符，
    先把当前字符加入 rows[curRow]。

    如果到达第 0 行，
    接下来必须向下走。

    如果到达最后一行，
    接下来必须向上走。

    然后根据 direction 更新 curRow。

    最后按照从上到下的顺序拼接所有行。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }

        vector<string> rows(numRows);

        int curRow = 0;
        int direction = 1;

        for (const auto &ch : s)
        {
            // 当前字符放入当前行
            rows[curRow] += ch;

            // 到达最上面，方向改成向下
            if (curRow == 0)
            {
                direction = 1;
            }
            // 到达最下面，方向改成向上
            else if (curRow == numRows - 1)
            {
                direction = -1;
            }

            curRow += direction;
        }

        string res;

        // 按照从上到下的顺序拼接
        for (const auto &row : rows)
        {
            res += row;
        }

        return res;
    }
};