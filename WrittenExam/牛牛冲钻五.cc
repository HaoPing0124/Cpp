// 牛牛最近在玩炉石传说，这是一款一对一对战的卡牌游戏，
// 牛牛打算努力冲上钻五分段，获得丰厚的天梯奖励。
// 炉石传说的段位可以用星数来表示
// 具体规则为:
//     若牛牛本场失败，则扣除一星;
//     若牛牛本场获胜，需要看牛牛是否触发了连胜奖励，
//     若牛牛获得了至少三连胜(即本局对局的上一局和上上局都获胜)则获得k星，否则获得一星。
// 现在给出牛牛游玩的n场记录，请你判断牛牛最终的星数和初始星数的差。


// 时间复杂度 O(n)
// 空间复杂度 O(n)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<char> s(n + 9);
        for (int i = 1; i <= n; ++i) cin >> s[i];

        vector<int> res(n + 9, 0);
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'W') {
                res[i] = 1;
                res[i] = res[i - 1] + res[i];
            }
        }

        int num = 0;
        for (int i = 1; i <= n; ++i) {
            if (res[i] == 0)
                num--;
            else if (res[i] < 3)
                num++;
            else if (res[i] >= 3)
                num += m;
        }
        cout << num << '\n';
    }
}
