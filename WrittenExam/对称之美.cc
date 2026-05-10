// 给出n个字符串，从第1个字符串一直到第n个字符串每个串取一个字母来构成一个新字符串，
// 新字符串的第i个字母只能从第行的字符串中选出，这样就得到了一个新的长度为n的字符串，
// 请问这个字符串是否有可能为回文字符串?

// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool check(string x, string y)
{
    unordered_map<char, int> mp;
    for(auto &c : x)
        mp[c]++;
    for(auto &c : y)
    {
        if(mp[c] > 0)
            return true;
    }
    return false;
}

int main() {
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<string> a(n + 9);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        
        bool flag = true;
        int left = 1, right = n;
        while(left + 1 < right)
        {
            if(!check(a[left], a[right]))
            {
                flag = false;
                break;
            }
            left++;
            right--;
        }

        cout << (flag ? "Yes" : "No") << '\n';
    }
}