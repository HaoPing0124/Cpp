// 给出一个正整数H，从1开始减，第一次必须减1
// 每次减的数字都必须和上一次相同或者是上一次的两倍，
// 请问最少需要几次能把H恰好减到0。

// 贪心 + 数学
#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--)
    {
        int res = 0, a = 1;
        int x; cin >> x;

        while(x)
        {
            x -= a;
            res++;

            if((x % (a * 2)) == 0)
                a *= 2;
        } 
        cout << res << endl;
    }
}