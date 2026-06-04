// 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

#include "Algorithm_150.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int cur1 = a.size() - 1, cur2 = b.size() - 1;
        int t = 0;
        while(cur1 >= 0 || cur2 >= 0 || t)
        {
            if(cur1 >= 0) t += a[cur1--] - '0';
            if(cur2 >= 0) t += b[cur2--] - '0';
            res += t % 2 + '0';
            t /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};