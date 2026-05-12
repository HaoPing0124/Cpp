// 你是一个勇士，现在你准备去森林刷毛球怪，你有两个属性(血量，攻击力)，毛球怪也有这两个属性。
// 当你遭遇一只毛球怪时你们会进入战斗，然后你和毛球怪轮流攻击(你先手)
// 每次使对方的血量减去自己攻击力的数值，当一方的血量小于等于0时死亡。
// 现在你想知道在自己活着的前提下最多杀死几只毛球怪。

// 数学
#include <iostream>
using namespace std;

int h, a, H, A;

int fun() {
    if (a >= H) {
        return -1;
    }
    int m = (H / a) + (H % a != 0 ? 1 : 0);
    int n = m - 1;
    int x = n * A;
    int res = h / x - (h % x == 0 ? 1 : 0);
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> h >> a >> H >> A;
        
        cout << fun() << '\n';
    }
}