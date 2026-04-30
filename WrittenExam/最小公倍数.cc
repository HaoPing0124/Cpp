// 正整数a和正整数b的最小公倍数，是指能被a和b整除的最小的正整数。
// 请你求a和b的最小公倍数。
// 比如输入5和7，5和7的最小公倍数是35，则需要返回35。


#include <iostream>
using namespace std;

using ll = long long;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

int main() {
    ll a, b;
    while (cin >> a >> b) {
        cout << lcm(a, b);
    }
}
