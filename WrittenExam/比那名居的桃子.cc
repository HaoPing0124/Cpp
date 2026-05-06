// 小红有一天看到了一只桃子，由于桃子看上去就很好吃，小红很想把它吃掉。
// 已知吃下桃子后，每天可以获得ai的快乐值，但是每天会获得bi的羞耻度。
// 桃子的持续效果一共为k天。
// 小红想知道，自己在哪一天吃下果实，可以获得尽可能多的快乐值?
// 如果有多个答案获得的快乐值相等，小红希望获得尽可能少的羞耻度。
// 如果有多个答案的快乐值和羞耻度都相等，由于小红实在太想吃桃子了，她希望尽可能早的吃下桃子。

// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<ll> fSum(n + 9), sSum(n + 9);
    for (int i = 1; i <= n; ++i)
        cin >> fSum[i];
    for (int i = 1; i <= n; ++i)
        cin >> sSum[i];

    ll left = 1, right = 1;
    ll fRes = 0, sRes = 0, fMax = 0, sMin = sSum[1], begin = 1;
    while (right <= n)
    {
        fRes += fSum[right];
        sRes += sSum[right];
        while (right - left + 1 > k)
        {
            fRes -= fSum[left];
            sRes -= sSum[left];
            left++;
        }

        if (right - left + 1 == k)
        {
            if (fRes > fMax)
            {
                fMax = fRes;
                sMin = sRes;
                begin = left;
            }
            else if (fRes == fMax && sRes < sMin)
            {
                sMin = sRes;
                begin = left;
            }
        }
        right++;
    }
    cout << begin << '\n';
}