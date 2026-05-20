// dd作为集训队的队长，一直掌管着集训室的空调遥控器，她需要调整温度使队员们更好地进入训练状态
// 已知集训室一共有n名队员，每位队员都有一个温度诉求a[i](1≤i≤n)
// 当室内温度为K时，当且仅当 |a[i] − K| ≤ p时，这个队员能够正常进入训练状态，否则就会开始躁动，作为队长，
// dd需要调整好温度，她想知道，在最佳情况下，最多有多少队员同时进入训练状态

#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e6 + 10;
int n, p;
int a[N];

// 排序 + 枚举所有温度 + 二分
int test01()
{
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        int target = a[i] + 2 * p;

        int l = -1, r = n;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] <= target)
                l = mid;
            else
                r = mid;
        }
        int end = l;
        int begin = i;
        res = max(res, end - begin + 1);
    }
    cout << res;
    return 0;
}

// 二分 + 滑动窗口
int test02()
{
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    int left = 0, right = 0;
    int target = 2 * p;
    int res = 0;
    while (right < n)
    {
        if (a[right] - a[left] <= target)
            right++;
        else
        {
            res = max(res, right - left);
            left++;
        }
    }
    cout << res;
    return 0;
}
