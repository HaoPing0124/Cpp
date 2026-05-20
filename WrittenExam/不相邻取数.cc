// 小红拿到了一个数组。
// 她想取一些不相邻的数，使得取出来的数之和尽可能大。
// 你能帮帮她吗？

// 动态规划 —— 线性dp（打家劫舍）
#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n;
int a[N], f[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        f[i + 2] = max(f[i + 1], f[i] + a[i]);
    }
    cout << f[n + 1];
    return 0;
}