// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法(先后次序不同算不同的结果)。
// 数据范围:0≤n≤40要求:时间复杂度:O(n)，空间复杂度:0(1)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 9, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n];
}