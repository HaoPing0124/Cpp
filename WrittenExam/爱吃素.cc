// 牛妹是一个爱吃素的小女孩，所以很多素数都害怕被她吃掉。
// 一天，两个数字a和b为了防止被吃掉，决定和彼此相乘在一起，这样被吃掉的风险就会大大降低
// 但仍有一定的可能被吃掉，请你判断他们相乘后是否仍有被吃掉的风险。
// 也就是说，请你判断a×b是否是素数。
// 素数是指大于1的正整数中，有且仅有两个因子的数。

#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

bool isPrim(ll x)
{
    if(x < 2) return false;
    for(int i = 2; i <= sqrt(x); ++i)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll a, b; cin >> a >> b;
        if((a == 1 && isPrim(b)) || (b == 1 && isPrim(a)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}