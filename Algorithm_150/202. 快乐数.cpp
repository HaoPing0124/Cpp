/*
题意：
    给定一个正整数 n，
    不断将 n 替换成它各位数字的平方和。

    如果最终能够变成 1，
    说明 n 是快乐数，返回 true。

    如果过程中出现重复数字，
    说明已经进入循环，不可能再到达 1，
    返回 false。

思路：
    使用 unordered_set 记录已经出现过的数字。

    每次计算 n 的各位数字平方和，
    得到新的 n。

    如果 n == 1，
    返回 true。

    如果发现当前 n 之前已经出现过，
    说明后续过程会不断重复，
    已经进入死循环，返回 false。

时间复杂度：O(log n)
空间复杂度：O(log n)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int getNext(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> seen;

        while (n != 1)
        {
            if (seen.count(n))
            {
                return false;
            }

            seen.insert(n);
            n = getNext(n);
        }

        return true;
    }
};