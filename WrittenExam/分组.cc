// dd当上了宣传委员，开始组织迎新晚会，已知班里有n个同学
// 每个同学有且仅有一个擅:长的声部，把同学们分成恰好m组
// 为了不搞砸节目，每一组里的同学都必须擅长同一个声部
// 当然，不同组同学擅长同一个声部的情况是可以出现的，毕竟一个声部也可以分成好几个part进行表演
// 但是他不希望出现任何一组的人过多，否则可能会导致场地分配不协调
// 也就是说，她希望人数最多的小组的人尽可能少
// 除此之外，对组内人员分配没有其他要求，她希望你告诉她，这个值是多少
// 如果无法顺利安排，请输出-1

//二分答案
// 时间复杂度：O(n + k log mx)
// 空间复杂度：O(k)
#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> mp;

bool check(int x) {
    int g = 0;
    for (auto &[a, b] : mp) {
        g += b / x + (b % x == 0 ? 0 : 1);  //记录按照x个人数来分，一共需要分多少组
        if(g > m) return false;
    }
    return g <= m;  //只有 g <= m 的分组才合法
}

int main() {
    cin >> n >> m;
    int mx = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mx = max(mx, ++mp[x]);
    }

    int kinds = mp.size();
    if (kinds <= m) {
        // // 暴力枚举
        // for (int i = 1; i <= mx; ++i) {
        //     if (check(i))
        //     {
        //         cout << i << '\n';
        //         break;
        //     }     
        // }
        int l = 1, r = mx + 1;
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    } else {
        cout << -1 << '\n';
    }
}