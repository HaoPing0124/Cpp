// 小红拿到了一个只由小写字母组成的字符串。
// 她准备把这个字符串重排(只改变字母的顺序，不改变数量)
// 重排后小红想让新字符串不包含任意两个相同的相邻字母。你能帮帮她吗?

// 贪心 + 构造
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    vector<int> cnt(26);
    char maxChar = ' ';
    int maxCount = 0;

    for (auto &c : s)
    {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] > maxCount)
        {
            maxCount = cnt[i];
            maxChar = char(i + 'a');
        }
    }

    if (maxCount > (n + 1) / 2)
    {
        cout << "no" << endl;
        return 0;
    }

    string res(n + 9, ' ');
    int pos = 0;

    while (cnt[maxChar - 'a'] > 0)
    {
        res[pos] = maxChar;
        pos += 2;

        cnt[maxChar - 'a']--;
    }

    for (int i = 0; i < 26; ++i)
    {
        while (cnt[i] > 0)
        {
            if (pos >= n)
                pos = 1;

            res[pos] = char(i + 'a');
            pos += 2;

            cnt[i]--;
        }
    }

    cout << "yes" << endl;
    cout << res << endl;
    return 0;
}