// 给定一个字符串，找到其中最长的回文子序列，并返回该序列的长度。
// 注:回文序列是指这个序列无论从左读还是从右读都是一样的。
// 本题中子序列字符串任意位置删除k(len(s)>=k>=0)个字符后留下的子串。
// 数据范围:字符串长度满足1 ≤ n ≤ 1000
// 进阶:空间复杂度O(n^2)，时间复杂度O(n^2)

// 动态规划 —— 区间dp
// 空间复杂度O(n^2)
// 时间复杂度O(n^2)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    
    for(int i = n - 1; i >= 0; --i)
    {
        dp[i][i] = 1;
        for(int j = i + 1; j < n; ++j)
        {
            if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    cout << dp[0][n - 1];
}