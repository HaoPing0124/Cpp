// 以字符串的形式读入两个数字，编写一个函数计算它们的和，以字符串形式返回。
// 数据范围:s.length,t.length ≤100000，字符串仅由0'~'9构成
// 要求:时间复杂度0(n)

#include"Algorithm.hpp"
#include <iterator>
class Solution {
  public:
    string solve(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int tmp = 0;
        string res;
        while (i >= 0 || j >= 0 || tmp) {
            if (i >= 0) tmp += s[i--] - '0';
            if (j >= 0) tmp += t[j--] - '0';
            res += tmp % 10 + '0';
            tmp /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
}; 