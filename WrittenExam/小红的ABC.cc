// 小红拿到了一个只包含 'a' , 'b' , 'c' 三种字符的字符串。
// 小红想知道，这个字符串最短的、长度超过 1 的回文子串的长度是多少？
// 子串定义：字符串取一段连续的区间。
// 例如"abcca"的子串有"ab"、"bcca"等但"aca"则不是它的子串。
// 回文的定义：一个字符串正着读和倒着读都是相同的，那么定义它的回文的。

// 模拟
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s; cin >> s;
    int n = s.size();
    
    int l = 0, r = 0;
    int res = -1;
    while(r < n && l + 1 < n)
    {
        r = l + 1;
        if(s[l] == s[r]){
            res = 2;
            break;
        }
        else{
            r++;
            if(s[l] == s[r])
                res = 3;
        }
        l++;
    }
    cout << res << endl;
    return 0;
}