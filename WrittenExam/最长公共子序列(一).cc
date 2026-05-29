// 给定两个字符串 s1 和 s2，长度为 n 和 m。求两个字符串最长公共子序列的长度。
// 所谓子序列，指一个字符串删掉部分字符（也可以不删）形成的字符串。
// 例如：字符串 "arcaea" 的子序列有 "ara" 、 "rcaa" 等。但 "car" 、 "aaae" 则不是它的子序列。
// 所谓 s1 和 s2 的最长公共子序列，即一个最长的字符串，它既是 s1 的子序列，也是 s2 的子序列。
// 数据范围 : 1≤m,n≤1000 。保证字符串中的字符只有小写字母。
// 要求：空间复杂度O(mn)，时间复杂度 O(mn)
// 进阶：空间复杂度O(min(m,n))，时间复杂度 O(mn)

#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
char s1[N], s2[N];
int dp[N][N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> s1[i];
    for (int i = 1; i <= m; ++i) cin >> s2[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m];
}
