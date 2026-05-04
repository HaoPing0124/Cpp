// 请你实现一个简单的字符串替换函数。
// 原串中需要替换的占位符为"%s",请按照参数列表的顺序一一替换占位符。
// 若参数列表的字符数大于占位符个数。则将剩下的参数字符添加到字符串的结尾。
// 给定一个字符串，同时给定一个参数数组。
// 题目保证参数列表字符不少于占位符个数。


#include "Algorithm.hpp"

class Solution {
public:
    string formatString(string str, vector<char>& arg) {
        int n = str.size();
        string res;
        int pos = 0;
        for(int i = 0; i < n; ++i)
        {
            if(str[i] == '%')
            {
                res += arg[pos++];
                i++;
                continue;
            }
            res += str[i];      
        }

        while(pos < arg.size())
            res += arg[pos++];
        return res;
    }
};