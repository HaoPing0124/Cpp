// chika很喜欢吃蜜柑。每个蜜柑有一定的酸度和甜度，chika喜欢吃甜的，但不喜欢吃酸的。
// 一共有n个蜜柑，chika吃k个蜜柑，将获得所吃的甜度之和与酸度之和。
// chika想获得尽可能大的甜度总和。
// 如果有多种方案，她希望总酸度尽可能小
// 。她想知道，最终的总酸度和总甜度是多少?

// TopK问题
// 规则排序
// 时间复杂度：O(n log n)
// 空间复杂度：O(n)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using PII = pair<int, int>;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;

    vector<PII> a(n + 9);
    for(int i = 1; i <= n; ++i) cin >> a[i].first;  // 酸度
    for(int i = 1; i <= n; ++i) cin >> a[i].second; // 甜度

    sort(a.begin() + 1, a.begin() + n + 1, [&](const PII &a, const PII &b){
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    ll s = 0, t = 0;
    for(int i = 1; i <= k; ++i)
    {
        s += a[i].first;
        t += a[i].second;
    }
    
    cout << s << ' ' << t << '\n';
}