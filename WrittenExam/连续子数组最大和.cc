// 给定一个长度为n的数组，数组中的数为整数。
// 请你选择一个非空连续子数组，使该子数组所有数之和尽可能大。
// 求这个最大值。

// 动态规划 —— 线性dp
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 9);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> dp(n + 9);
    int res = INT16_MIN;
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1], 0) + a[i];
        res = max(res, dp[i]);
    }

    cout << res << '\n';
}