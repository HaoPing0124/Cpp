// 牛牛举办了一次编程比赛，参加比赛的有3*n个选手，每个选手都有一个水平值a。
// 现在要将这些选:手进行组队，一共组成n个队伍，即每个队伍3人。
// 牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
// 例如:
//     如果一个队伍三个队员的水平值分别是3、3、3，那么队伍的水平值是3。
//     如果一个队伍三个队员的水平值分别是3、2、3，那么队伍的水平值是3。
//     如果一个队伍三个队员的水平值分别是1、5、2，那:么队伍的水平值是2。
// 为了让比赛更有看点，牛牛想安排队伍使所有队伍的水平值总和最大。

// 贪心
// 时间复杂度：O(n log n)
// 空间复杂度：O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int len = n * 3;
    vector<long long> a(len);
    for (int i = 0; i < len; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    int pos = len - 2;
    long long res = 0;
    int count = 0;
    while (count++ < n && pos >= 0)
    {
        res += a[pos];
        pos -= 2;
    }

    cout << res << '\n';
}