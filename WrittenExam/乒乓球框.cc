// 

// 时间复杂度：O(n + m)
// 空间复杂度：O(k)    //最坏256
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> mp;
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() < s2.size()) {
        cout << "No" << '\n';
        return 0;
    }

    for (auto& c : s1)
        mp[c]++;

    // for (auto& c : s2)
    //     mp[c]--;

    // for (auto &[x, y] : mp) {
    //     if (y < 0) {
    //         cout << "No" << '\n';
    //         return 0;
    //     }
    // }

    for (auto& c : s2) {
        mp[c]--;
        if (mp[c] < 0) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
}