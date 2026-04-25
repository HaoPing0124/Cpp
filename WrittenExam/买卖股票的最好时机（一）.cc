#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n + 9, 0);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    // mx:最大利润，mi:最佳买入点
    int mx = 0, mi = INT_MAX;
    for(int i = 1; i <= n; ++i)
    {
        mi = min(mi, arr[i]);
        mx = max(mx, arr[i] - mi);
    }
    cout << mx;
}
