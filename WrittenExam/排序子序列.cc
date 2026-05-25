// 牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
// 牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,
// 牛牛想知道他最少可以把这个数组分为几段排序子序列.

// 模拟 —— 画折线图
#include <iostream>
using namespace std;

const int N = 1e5 + 9;
int n, res, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int pos = 1;

    while (pos <= n) {
        if (pos == n) {
            res++;
            break;
        }
        if (a[pos] < a[pos + 1]) {
            while (pos <= n && a[pos] <= a[pos + 1]) pos++;
            res++;
        }
        else if (a[pos] > a[pos + 1]) {
            while (pos <= n && a[pos] >= a[pos + 1]) pos++;
            res++;
        }
        // else
        // {
        //     // while(pos <= n && a[pos] == a[pos + 1]) pos++;
        // }
        pos++;
    }
    cout << res << endl;
}