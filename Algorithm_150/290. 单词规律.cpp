/*
题意：
    给定字符串 pattern 和字符串 s，
    判断 s 中的单词是否按照 pattern 的字符规律进行匹配。

    要求 pattern 中字符和 s 中单词之间存在一一对应关系：
        1. 相同字符必须始终映射到同一个单词；
        2. 不同字符不能映射到同一个单词；
        3. 相同单词也不能映射到不同字符。

思路：
    使用双向哈希映射。

    不使用 stringstream，
    直接手动扫描字符串 s，
    遇到空格时得到一个完整单词。

    mapPS 记录：
        pattern 字符 -> 单词

    mapSP 记录：
        单词 -> pattern 字符

    每取出一个单词，
    就和 pattern 当前字符建立双向映射。

    如果任意一个方向已有映射且不一致，
    返回 false。

    最后还要保证：
        pattern 中的字符数量
        和 s 中的单词数量完全相同。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include"Algorithm_150.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mapPS;
        unordered_map<string, char> mapSP;

        int n = s.size();
        int i = 0;
        int idx = 0;

        while(i < n)
        {
            // pattern 已经没有字符，但 s 还有单词
            if(idx >= pattern.size())
            {
                return false;
            }

            // 找当前单词的结束位置
            int j = i;
            while(j < n && s[j] != ' ')
            {
                ++j;
            }

            // 截取当前单词
            string word = s.substr(i, j - i);
            char ch = pattern[idx];

            // 字符 -> 单词 映射冲突
            if(mapPS.count(ch) && mapPS[ch] != word)
            {
                return false;
            }

            // 单词 -> 字符 映射冲突
            if(mapSP.count(word) && mapSP[word] != ch)
            {
                return false;
            }

            mapPS[ch] = word;
            mapSP[word] = ch;

            ++idx;

            // j 当前指向空格，跳到下一个单词开头
            i = j + 1;
        }

        // pattern 还有剩余字符，说明单词数量不够
        return idx == pattern.size();
    }
};