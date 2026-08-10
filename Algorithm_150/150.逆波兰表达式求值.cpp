/*
题意：
    给定一个字符串数组 tokens，表示一个逆波兰表达式。

    逆波兰表达式中：
        数字表示操作数；
        运算符表示对前面的两个数字进行计算。

    计算该表达式并返回结果。
    支持运算符：+ - * /
    除法采用整数除法，并且向零截断。

思路：
    使用栈保存计算过程中的数字。
    遍历 tokens：
    如果当前字符串是运算符：
        从栈顶依次取出两个操作数。

    如果当前字符串不是运算符：
        说明是数字，
        使用 stoi 转换为整数后压入栈。

    使用 map 保存运算符和对应计算函数：
        "+" -> 加法
        "-" -> 减法
        "*" -> 乘法
        "/" -> 除法
    这样可以避免大量 if else 判断。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"
#include <functional>

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        map<string, function<int(int, int)>> opFunMap = {
            {"+", [](int x, int y)
             { return x + y; }},
            {"-", [](int x, int y)
             { return x - y; }},
            {"*", [](int x, int y)
             { return x * y; }},
            {"/", [](int x, int y)
             { return x / y; }}};

        for (auto &str : tokens)
        {
            // 当前字符串是运算符
            if (opFunMap.count(str))
            {
                // 栈顶是右操作数
                int right = st.top();
                st.pop();

                // 第二个弹出的是左操作数
                int left = st.top();
                st.pop();

                // 计算结果重新入栈
                st.push(opFunMap[str](left, right));
            }
            else
            {
                // 数字直接入栈
                st.push(stoi(str));
            }

            return st.top();
        }
    }
};