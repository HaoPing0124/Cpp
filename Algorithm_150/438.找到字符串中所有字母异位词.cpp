// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。
// 不考虑答案输出的顺序。

// 定长滑动窗口 + 哈希
// 时间复杂度: O(n)
// 空间复杂度: O(1)
#include "Algorithm_150.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> res;
        int hash1[26] = { 0 };  // 统计字符p 每个字母所出现的次数，后续都要以此进行比较
        int hash2[26] = { 0 };  // 统计窗口中每个字母所出现的次数
        
        for(auto &x : p)
            hash1[x - 'a']++;
        
        int l = 0, r = 0;
        int count = 0;      // 统计有效字符个数(不重复的 p 的 异位词)
        while(r < n)
        {
            char in = s[r];
            // 如果新加入的字母 在窗口中出现的次数 <= 1 (也就是在加入前，次数为0, 这样的添加才不是重复的)
            if(++hash2[in - 'a'] <= hash1[in - 'a']) count++;   // 非重复 且 是 p 中出现的字母，count++

            // 如果窗口大小超过 p 的长度(因为需要固定窗口大小) 就要收缩左边界
            if(r - l + 1 > m)
            {
                char out = s[l++];
                // 收缩了左边界 就要将删除的那个字母 与 p字母对比
                // 如果被删除的字母，是p中出现的字母 且 删除后次数 <= 1 (也就是没删除前 次数 == 1, 是一个没重复过的字母)
                if(--hash2[out - 'a'] < hash1[out - 'a']) count--;  // 非重复 且 是 p 中出现的字母被删除，count--
            }

            // 最后才能 r++, 否则 在判断 if(r - l + 1 > m) 时，r 的值已经被加过了，窗口大小就变成了 p + 1
            r++;

            // 如果 有效次数 和 字符p长度 相同，说明完美符合条件
            if(count == m) res.push_back(l);
        }
        return res;
    }
};