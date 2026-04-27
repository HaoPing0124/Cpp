// 给定一个正整数N(1≤N≤2x10^9)
// 现在需要将其转换为千分位格式，即从整数最低位开始，
// 每三位数字插入一个英文逗号，以提高可读性。
// 例如，对于980364535，转换后为980,364,535
// 请编写程序完成该格式转换。

#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; ++i) {
            res += s[i];
            // n - i - 1
            if ((n - i - 1) % 3 == 0 && i != n - 1) res += ',';
        }
        cout << res;
    }
}