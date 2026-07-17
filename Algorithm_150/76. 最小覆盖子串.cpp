/*
题意：
    给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串
    使得该子串包含 t 中的每一个字符（包括重复字符）。
    如果没有这样的子串，返回空字符串 ""。
    测试用例保证答案唯一。

思路：
    滑动窗口 + 哈希表
    使用滑动窗口维护字符串 s 中的一段连续区间 [l, r]。
    使用 need 数组记录当前窗口还需要多少个字符，初始时统计字符串 t 中每个字符的数量。
        need[ch] > 0 表示当前窗口还缺少字符 ch；
        need[ch] == 0 表示当前窗口中的字符 ch 数量刚好足够；
        need[ch] < 0 表示当前窗口中存在多余的字符 ch。

    右指针 right 不断向右移动，将新字符加入窗口：
        如果加入前 need[in] > 0，说明当前字符是窗口缺少的有效字符，
        因此 count 加一，然后将 need[in] 减一。

    当 count 等于 t.size() 时，说明当前窗口已经包含 t 中的全部字符：
        记录当前窗口的长度，并尝试移动左指针 left 缩小窗口；
        左端字符离开窗口时，将 need[out]++；
        如果增加后 need[out] > 0，说明窗口开始缺少该字符，
        因此 count--，停止收缩，继续移动右指针。

    遍历过程中只记录最短窗口的起始位置和长度，
    最后使用 substr 截取一次最终答案，避免反复创建字符串。

时间复杂度：O(N + M)
    N 是字符串 s 的长度，M 是字符串 t 的长度。

空间复杂度：O(1)
    need 数组的长度固定为 256，与输入字符串长度无关。
*/

#include "Algorithm_150.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty() || s.empty() || s.size() < t.size())
            return "";

        int need[256] = {0}; // 存储还需要的字母个数
        int n = s.size(), m = t.size();
        int l = 0, count = 0;
        int min_len = INT_MAX, start = 0;

        for (auto &ch : t)
            need[ch]++;

        for (int r = 0; r < n; ++r)
        {
            char in = s[r];
            // 如果是需要的字母
            if (need[in]-- > 0)
                count++;

            // 符合条件，开始试着缩小窗口，寻找更短子串
            while (count == m)
            {
                // 当前合法的子串长度
                int len = r - l + 1;

                // 如果找的的子串更小
                if (min_len > len)
                {
                    min_len = len; // 更新目前最小子串长度
                    start = l;     // 更新起始位置
                }

                // 缩短窗口 out为要弹出的字母
                char out = s[l];
                need[out]++;

                // 如果弹出后>0 说明开始缺少字母了
                // 如果一开始就不是 t 所需要的字母, 那么原本 need[out] 一定 <= -1,
                // 所以能>0 的一定是原本 t 需要的字母
                if (need[out] > 0)
                    count--;
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};