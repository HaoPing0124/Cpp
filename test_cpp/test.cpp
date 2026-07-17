#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || s.size() < t.size()) return "";
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;
        string res = "";

        for (auto& ch : t) hash1[ch]++;
        int n = s.size(), m = t.size();
        int l = 0, count = 0;
        int minStr = INT_MAX, len = 1;
        for (int r = 0; r < n; ++r, ++len)
        {
            if (hash1[s[r]] && ++hash2[s[r]] <= hash1[s[r]]) count++;

            if (count == m && minStr > len)
            {
                minStr = len;
                res = s.substr(l, len);
            }
            while (count == m)
            {
                if (hash1[s[l]] && --hash2[s[l]] < hash1[s[l]]) count--;
                len--;
                l++;
            }
        }
        return res;
    }
};

int main()
{
    Solution test;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string res = test.minWindow(s, t);
    return 0;
}