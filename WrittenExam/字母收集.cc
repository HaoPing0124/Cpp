// 有一个n*m的矩形方阵，每个格子上面写了一个小写字母。
// 小红站在矩形的左上角，她每次可以向右或者向下走，
// 走到某个格子上就可以收集这个格子的字母。
// 小红非常喜欢"love"这四个字母。
// 她拿到一个1字母可以得4分，拿到一个o字母可以得3分，
// 拿到一个v字母可以得2分，拿到一个e字母可以得1分。
// 她想知道，在最优的选择一条路径的情况下，她最多能获取多少分?

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> a(n + 9, vector<char>(m + 9));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> a[i][j];

        vector<int> dp((m + 9));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int p = 0;
                switch (a[i][j]) {
                    case 'l': p = 4; break;
                    case 'o': p = 3; break;
                    case 'v': p = 2; break;
                    case 'e': p = 1; break;
                }

                dp[j] = max(dp[j], dp[j - 1]) + p;
            }
        }
        cout << dp[m];

    }
}
