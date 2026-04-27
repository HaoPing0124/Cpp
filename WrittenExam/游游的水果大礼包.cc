// 游游有n个苹果，m个桃子。
// 她可以把2个苹果和1个桃子组成价值a元的一号水果大礼包，
// 也可以把1个苹果和2个桃子组成价值b元的二号水果大礼包。
// 游游想知道，自己最多能组成多少价值总和的大礼包?

#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll res = 0;
    
    // 枚举每次取x个a价值礼包时，还能凑成b价值礼包 总和的最大值
    for(int x = 0; x <= min(n / 2, m); ++x)
    {
        // 计算能凑成b礼包的个数(m - x) 前提是 已选a礼包剩下的数量(n - x * 2)
        int y = min(n - x * 2, (m - x) / 2);    
        res = max(res, x * a + y * b);
    }
    cout << res;
}
