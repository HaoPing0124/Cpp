// 给出6根棍子，能否在选出3根拼成一个三角形的同时剩下的3根也能组成一个三角形?

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int main() {
    while (cin >> t) { // 注意 while 处理多个 case
        while (t--) {
            int n = 6;
            vector<int>a(n, 0);
            for (int i = 0; i < n; ++i) cin >> a[i];
            sort(a.begin(), a.end());

            if (a[0] + a[1] > a[2] && a[3] + a[4] > a[5] ||
                    a[0] + a[2] > a[3] && a[1] + a[4] > a[5] ||
                    a[0] + a[3] > a[4] && a[1] + a[2] > a[5] ||
                    a[0] + a[4] > a[5] && a[1] + a[2] > a[3]
               ) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")