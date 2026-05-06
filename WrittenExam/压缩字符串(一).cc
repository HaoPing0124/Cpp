// 利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
// 比如，字符串aabcccccaaa会变为a2bc5a3。
// 1.如果只有一个字符，1不用写
// 2.字符串中只包含大小写英文字母(a至z)。
// 数据范围:
//     0<=字符串长度<=50000
// 要求:时间复杂度O(N)

// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(n)

#include "Algorithm.hpp"

class Solution
{
public:
    string compressString(string param)
    {
        int left = 0, right = 0;
        int n = param.size();
        string res;
        while (right < n)
        {
            int count = 0;
            res += param[left];
            while (right < n && param[right] == param[left])
            {
                count++;
                right++;
            }

            if (count > 1)
                res += to_string(count);

            left = right;
        }
        return res;
    }
};