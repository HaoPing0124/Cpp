/*
题意：
    给定一个整数数组 heights，
    heights[i] 表示第 i 根柱子的高度，
    每根柱子的宽度都是 1。

    求柱状图中能够构成的最大矩形面积。

思路：
    使用单调栈。

    栈中保存柱子的下标，并保持对应高度单调不下降。

    遍历每根柱子：
        如果当前柱子高度大于等于栈顶柱子，
        当前柱子还可能继续向右扩展，直接将下标入栈。

        如果当前柱子比栈顶柱子矮，
        说明栈顶柱子的右边界已经确定，
        不可能继续向右扩展，因此将栈顶下标弹出并计算面积。

    弹出下标 mid 后：
        heights[mid] 是当前矩形高度；
        当前下标 i 是右边第一个比它矮的位置；
        弹栈后的新栈顶是左边第一个比它矮的位置。

    左边界：
        left = st.empty() ? -1 : st.top()

    右边界：
        right = i

    因此矩形宽度为：
        right - left - 1

    面积为：
        heights[mid] * (right - left - 1)

    遍历到数组末尾时，
    将当前位置看作一个高度为 0 的柱子，
    使栈中剩余柱子全部完成结算。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int res = 0;

        // 栈中保存下标，并保持对应高度单调不下降
        stack<int> st;

        // i == n 时相当于在末尾添加一个高度为 0 的柱子
        for (int i = 0; i <= n; ++i)
        {
            // 当前柱子更矮时，栈顶柱子的右边界已经确定
            // i == n 放在 || 左边，利用短路避免访问 heights[n]
            while (!st.empty() && (i == n || heights[st.top()] > heights[i]))
            {
                int mid = st.top();
                st.pop();

                // 弹栈后的栈顶是左边第一个更矮的位置
                int left = st.empty() ? -1 : st.top();

                // i 是右边第一个更矮的位置
                int width = i - left - 1;

                res = max(res, heights[mid] * width);
            }

            // i == n 只是用于清空栈，不是真实柱子
            if (i < n)
            {
                st.push(i);
            }
        }

        return res;
    }
};