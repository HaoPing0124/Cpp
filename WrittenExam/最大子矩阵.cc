// 已知矩阵的大小定义为矩阵中所有元素的和。
// 给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。
// 比如，如下4 * 4的矩阵
//     0 -2 -7 0
//     9  2 -6 2
//    -4  1 -4 1
//    -1  8 0 -2
// 的最大子矩阵是 
//     9 2
//    -4 1 
//    -1 8
// 这个子矩阵的大小是15。

#include <iostream>
#include <vector>
    using namespace std;

const int N = 110;
int n;
// vector<vector<int>> dp()
int dp[N][N];

int main()
{
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> x;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + x;
        }
    }
    int res = -127 * n;
    for (int x1 = 1; x1 <= n; ++x1)
    {
        for (int y1 = 1; y1 <= n; ++y1)
        {
            for (int x2 = x1; x2 <= n; ++x2)
            {
                for (int y2 = y1; y2 <= n; ++y2)
                {
                    res = max(res, dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
                }
            }
        }
    }
    cout << res << '\n';
}