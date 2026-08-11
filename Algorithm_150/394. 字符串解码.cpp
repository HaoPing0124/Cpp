/*
题意：
    给定一个经过编码的字符串 s，
    编码规则为 k[encoded_string]，
    表示将括号中的字符串重复 k 次。

    字符串中可能存在多层嵌套，
    返回完整解码后的字符串。

思路：
    使用两个栈保存进入每一层括号之前的状态。

    numSt 保存当前括号对应的重复次数，
    strSt 保存进入当前括号之前已经得到的字符串，
    cur 保存当前正在构造的字符串，
    num 保存当前读取到的重复次数。

    遍历字符串：

    遇到数字时：
        使用 num = num * 10 + (ch - '0') 计算重复次数，
        从而处理 10、20 等多位数字。

    遇到 '[' 时：
        将当前 num 压入 numSt，
        将当前 cur 压入 strSt，
        然后将 num 清零、cur 清空，
        开始处理新的一层括号。

    遇到 ']' 时：
        当前 cur 就是这一层括号中已经解码完成的字符串。

        取出这一层的重复次数 count，
        将 cur 重复 count 次，
        再拼接到进入这一层之前保存的字符串后面。

    遇到普通字母时：
        直接加入 cur。

    遍历结束后，cur 就是最终解码结果。

时间复杂度：O(|s| + T)
    T 表示解码过程中实际进行的字符串构造和复制总量。
空间复杂度：O(|s| + L)
    L 表示最终解码字符串的长度。
*/

#include "Algorithm_150.h"

class Solution
{
public:
    string decodeString(string s)
    {
        // 保存每一层括号对应的重复次数
        stack<int> numSt;

        // 保存进入每一层括号之前的字符串
        stack<string> strSt;

        string cur;
        int num = 0;

        for (const auto &ch : s)
        {
            if (isdigit(ch))
            {
                // 处理多位数字，例如 12[a]
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                // 保存进入当前括号前的状态
                numSt.push(num);
                strSt.push(cur);

                // 开始处理新的一层
                num = 0;
                cur.clear();
            }
            else if (ch == ']')
            {
                // 取出当前这一层需要重复的次数
                int count = numSt.top();
                numSt.pop();

                // 取出进入这一层之前的字符串
                string prev = strSt.top();
                strSt.pop();

                // 将当前字符串重复 count 次并拼接到上一层
                for (int i = 0; i < count; ++i)
                {
                    prev += cur;
                }

                cur = prev;
            }
            else
            {
                // 普通字母直接加入当前字符串
                cur += ch;
            }
        }

        return cur;
    }
};