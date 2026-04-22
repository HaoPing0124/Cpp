// 以字符串的形式读入两个数字，编写一个函数计算它们的乘积，以字符串形式返回。
// 数据范围:读入的数字大小满足 0 ≤ n ≤ 101000
// 要求:空间复杂度O(m)，时间复杂度O(m2)(假设m是n的长度)

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b)
    { // 注意 while 处理多个 case
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = a.size(), m = b.size();

        vector<int> tmp(m + n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                tmp[i + j] += (a[i] - '0') * (b[j] - '0');
            }
        }

        int c = 0;
        string res;
        // 处理进位
        for (auto &x : tmp)
        {
            c += x;
            res += c % 10 + '0';
            c /= 10;
        }

        // 处理多余进位，如百位进位
        while (c)
        {
            res += c % 10 + '0';
            c /= 10;
        }

        // 处理头部零
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();

        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}
// 64 位输出请用 printf("%lld")
