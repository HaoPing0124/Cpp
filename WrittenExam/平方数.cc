// 牛妹是一个喜欢完全平方数的女孩子。
// 牛妹每次看到一个数x，都想求出离x最近的完全平方数y。
// 每次手算太麻烦，所以牛妹希望你能写个程序帮她解决这个问题。
// 形式化地讲，你需要求出一个正整数y，满足y可以表示成a2(a是正整数)，使得|x-y|的值最小。
// 可以证明这样的y是唯一的。

// 数学
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll x = sqrt(n);

    ll res1 = x * x;
    ll res2 = (x + 1) * (x + 1);

    // 不能都是res - n, 前一个为 n - res, 后一个为 res - n
    cout << (n - res1 < res2 - n ? res1 : res2 ) << '\n';
}