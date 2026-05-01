// 对于长度为n的一个字符串A(仅包含数字，大小写英文字母)
// 请设计一个高效算法，计算其中最长回文子串的长度。
// 数据范围:1≤n≤1000
// 要求:空间复杂度O(1)，时间复杂度O(n^2)
// 进阶:空间复杂度O(n)，时间复杂度O(n)  //马拉车算法


#include "Algorithm.hpp"

// 中心扩展法
// 时间复杂度O(n^2),空间复杂度O(1)
class Solution {
  public:
    int getLongestPalindrome(string A) {
        int n = A.size();
        int left = 0, right = 0;

        int len = 0;
        for (int i = 0; i < n; ++i) {
            // 字符串个数为奇数
            left = i - 1, right = i + 1;
            while (left >= 0 && right >= 0 && right < n && A[left] == A[right]){
                left--;
                right++;
            }
            len = max(len, right - left - 1);

            // 字符串个数为偶数
            left = i, right = i + 1;
            while (left >= 0 && right >= 0 && right < n && A[left] == A[right]){
                left--;
                right++;
            }
            len = max(len, right - left - 1);
        }
        return len;
    }
};

