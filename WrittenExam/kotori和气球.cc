// kotori最近迷上了摆气球的游戏。她一共有n种气球，每种气球有无数个。
// 她要拿出若干个气球摆成一排。
// 但是，由于气球被施放了魔法，同样种类的气球如果相邻会发生爆炸
// 因此若两个相邻的气球种类相同被视为不合法的。
// kotori想知道，摆成一排m个一共有多少种不同的方案？
// 由于该数可能过大，只需要输出其对109取模的结果。

// 数学——排列组合
#include <iostream>
using namespace std;

const int MOD = 109;

int main()
{
    int n, m;
    cin >> n >> m;
    
    long long res = n;
    for(int i = 0; i < m - 1; ++i)
    {
        res = res * (n - 1) % MOD;
    }
    cout << res << '\n';
    return 0;
}