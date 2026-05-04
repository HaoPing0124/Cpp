// 给出一个区间[a，b]，计算区间内“神奇数”的个数。
// 神奇数的定义:存在不同位置的两个数位，组成一个两位数(且不含前导0)，且这个两位数为质数。
// 比如:153，可以使用数字3和数字1组成13,13是质数，满足神奇数。
// 同样153可以找到31和53也为质数，只要找到一个质数即满足神奇数。

// 枚举 + 数学(求质数)
// 时间复杂度：O(n log^2 n)
// 空间复杂度：O(log n)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;

    int lim = sqrt(n);
    for (int i = 2; i <= lim; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int check(int n)
{
    vector<int> a;
    while (n)
    {
        a.push_back(n % 10);
        n /= 10;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a.size(); ++j)
        {
            if (i != j && a[i] != 0)
            {
                if (isprime(a[i] * 10 + a[j]))
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = max(n, 10); i <= m; ++i)
        res += check(i);
    cout << res;
}