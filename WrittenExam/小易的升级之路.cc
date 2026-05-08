// 小易准备打怪升级，他将依次遇到n个怪物，每个怪物的战斗力是ai。
// 小易初始的战斗力是x。
// 当小易的战力不小于当前遇到怪物的战斗力时，小易会获得该战斗力的数值的战斗力。
// 否则，小易会获得自身战斗力和怪物战斗力的最大公约数的战斗力。
// 小易想知道，自己最终的战斗力是多少?

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ll n, x;
    cin >> n >> x;
    
    vector<int> a(N);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        if (x >= a[i])
            x += a[i];
        else
            x += gcd(x, a[i]);
    }
    cout << x;
}