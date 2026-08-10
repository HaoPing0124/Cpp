/*
题意：
    假设正在爬楼梯，需要 n 阶才能到达楼顶。
    每次可以爬 1 阶或者 2 阶。
    求到达楼顶共有多少种不同的方法。

思路：
    使用动态规划。
    定义：
        f[i] 表示爬到第 i 阶的方法数量。

    到达第 i 阶有两种情况：
        1. 从第 i - 1 阶爬 1 阶：
            f[i - 1]
        2. 从第 i - 2 阶爬 2 阶：
            f[i - 2]

    所以状态转移：
        f[i] = f[i - 1] + f[i - 2]

    初始化：
        f[0] = 1
        表示站在地面，不爬也算一种方法。
        f[1] = 1
        表示只有一种方法爬到第一阶。

    也可以理解为：
        n 阶爬楼梯问题就是斐波那契数列。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include "Algorithm_150.h"

// class Solution {
// public:
//     int climbStairs(int n) {
//         long long f[50] = { 0 };
//         f[0] = 1; f[1] = 1;
//         for (int i = 0; i <= n; ++i)
//             f[i + 2] = f[i + 1] + f[i];
//         return f[n];
//     }
// };

class Solution
{
public:
    int climbStairs(int n)
    {
        long long f[50] = {0};

        // 初始化边界
        f[0] = 1; f[1] = 1;

        // 从第 2 阶开始计算
        for (int i = 2; i < n; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n];
    }
};