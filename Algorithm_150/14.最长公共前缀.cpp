// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""

// 字符串模拟
#include"Algorithm_150.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; ++i) {
            res = FindStr(res, strs[i]);
        }
        return res;
    }

    string FindStr(string& str1, string& str2) {
        int i = 0;
        int len = min(str1.size(), str2.size());
        while (i < len && str1[i] == str2[i])
            i++;
        return str1.substr(0, i);
    }
};