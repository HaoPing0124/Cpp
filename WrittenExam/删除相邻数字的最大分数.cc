// 给定一个长度为n的仅包含正整数的数组，另外有一些操作，
// 每次操作你可以选择数组中的任意一个元素ai
// 同时数组中所有等于 ai-1 和 ai+1的元素会被全部移除，同时你可以得到ai分
// 直到所有的元素都被选择或者删除。
// 请你计算最多能得到多少分。
// 数据范围:数组长度满足1≤n≤10^5，数组中的元素大小都满足1≤ai≤10^4

// 动态规划——线性dp
// 时间复杂度：O(n)
// 空间复杂度：O(n)
// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 1e4 + 9;

// int n;
// vector<int> res(N);
// vector<int> f(N);
// vector<int> g(N);

// int main() {
//     cin >> n;
//     int x = 0;
//     for (int i = 0; i < n; ++i) {
//         cin >> x;
//         res[x] += x;
//     }

//     for (int i = 1; i < N; ++i) {
//         f[i] = g[i - 1] + res[i];
//         g[i] = max(f[i - 1], g[i - 1]);
//     }

//     cout << max(f[N - 1], g[N - 1]) << '\n';
// }

// 优化空间版本 —— 滚动变量优化dp
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int N = 1e4 + 9;

int n;
vector<ll> res(N);

int main()
{
    cin >> n;
    int x = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        res[x] += x;
        mx = max(mx, x);
    }

    ll take = 0, skip = 0;
    for (int i = 1; i <= mx; ++i)
    {
        ll new_take = skip + res[i];
        ll new_skip = max(take, skip);

        take = new_take;
        skip = new_skip;
    }

    cout << max(take, skip) << '\n';
}