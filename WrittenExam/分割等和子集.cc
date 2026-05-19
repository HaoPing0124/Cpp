// 给定一个只包含正整数的数组 nums
// 请问能否把这个数组取出若干个数使得取出的数之和和剩下的数之和相同。

// 01背包
#include <iostream>
using namespace std;

const int N = 510, M = 110 * 510 / 2;
int n;
int a[N];
bool dp[N][M];

bool fun(int sum)
{
    if(sum % 2 == 1) return false;

    sum /= 2;
    dp[0][0] = true;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= sum; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - a[i]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << (fun(sum) ? "true" : "false") << endl;
    return 0;
}