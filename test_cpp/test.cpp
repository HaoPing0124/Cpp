#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m) { // 注意 while 处理多个 case
        vector<int> a(n + 9);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        if (a[1] >= m)
        {
            cout << 1 << " " << 1;
            return 0;
        }

        //滑动窗口
        int left, right;
        left = 1, right = 2;
        int res_l = 0, res_r = 0;

        int len = INT_MAX;

        int res = a[left];

        while (left < n && right < n)
        {
            if (res >= m)
            {
                if ((right - left) < len)
                {
                    len = right - left;
                    res_l = left;
                    res_r = right - 1;
                }
                res -= a[left--];
                // left--;
            }
            else
            {
                res += a[right];
                if (res >= m)
                    continue;
                right++;
            }

        }




        cout << res_l << " " << res_r;
    }
}
// 64 位输出请用 printf("%lld")