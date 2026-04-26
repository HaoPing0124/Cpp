// 给定无序数组arr，返回其中最长的连续序列的长度
// (要求值连续，位置可以不连续,例如3,4,5,6为连续的自然数)

#include "Algorithm.hpp"

class Solution {
  public:
    int MLS(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int res = 0;
        for (auto x : st) {
            int len = 1;
            //前面-1的数字存在 不是子串开头
            if (st.count(x - 1)) continue;

            //是开头
            int y = x;
            while (st.count(y + 1)) {
                y++;
                len++;
            }
            res = max(res, len);
        }
        return res;
    }
};