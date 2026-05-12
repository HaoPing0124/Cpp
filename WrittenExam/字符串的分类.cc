// 有n个字符串，将这些字符串分类，两个字符串A和B属于同一类
// 需要满足以下条件:
//     A中交换任意位置的两个字符，最终可以得到B，交换的次数不限。
// 比如:abc与bca就是同一类字符串。这n个字符串可以分成几类?

// 哈希 / 集合
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<string> st;
    while(n--)
    {
        string s; cin >> s;
        sort(s.begin(), s.end());
        st.insert(s);
    }
    cout << st.size();
}