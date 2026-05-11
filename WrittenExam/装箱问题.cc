// 有一个箱子容量为V(正整数，0≤V≤20000)
// 同时有n个物品(0<n≤30)，每个物品有一个体积(正整数)。
// 要求n个物品中，任取若干个装入箱内（每个物品取一次），使箱子的剩余空间为最小。

// 01背包问题
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 二维
int test1()
{
    int v, n;
    vector<int> a(35);
    vector<vector<int>> dp(35, vector<int>(20010));
    cin >> v;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // i 表示枚举第几个物品
    for (int i = 1; i <= n; ++i)
    {
        // j 表示有背包的容量，从0开始枚举每一个容量的情况
        for (int j = 0; j <= v; ++j)
        {
            // 最坏情况下就是不选
            dp[i][j] = dp[i - 1][j];
            // 若背包容量够装下 第i个 物品
            if (j >= a[i])
                // 如果要装，就要先腾下 这第i个物品 的位置，再加上它的价值
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
        }
    }
    cout << (v - dp[n][v]);
}

// 优化空间为一维
int test2()
{
    int v, n;
    vector<int> a(35);
    vector<int> dp(20010);
    cin >> v;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        // j为空间余量，j >= a[i] 所以一定装得下 第i个 物品
        for (int j = v; j >= a[i]; --j)
        {
            // 不拿 和 硬要拿(腾出这 第i个 物品 的空间) 然后加上该物品价值 比较
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << (v - dp[v]);
}