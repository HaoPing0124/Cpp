// 给定一个包含n个正整数的数组a[1]，a[2]，...,a[n]。
// 你需要从中选择若干个数(可以全部也可以一个都不选)，
// 使得在所选集合中任意两数的差的绝对值均不超过给定整数k。
// 请输出能够选出的元素个数的最大值。

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 9;

int res, a[N];

int main() {
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);

    int l = 1, r = 1;
    while(r <= n)
    {
        while(a[r] - a[l] > k) l++;
        res = max(res, r - l + 1);
        r++;
    }
    cout << res << endl;
}