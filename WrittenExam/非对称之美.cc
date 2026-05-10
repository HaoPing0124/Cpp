// 给出一个字符串，求最长非回文子字符串的长度

// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include <iostream>
using namespace std;

int fun(const string &s)
{
    bool flag = true;
    int n = s.size();
    if(n == 1) return 0;
    for(int i = 1; i < n; ++i)
    {
        if(s[0] != s[i])
        {
            flag = false;
            break;
        }
    }
    if(flag) return 0;

    flag = true;
    int left = 0, right = n - 1;
    while(left < right)
    {
        if(s[left++] != s[right--])
        {
            flag = false;
            break;
        }
    }
    return flag ? n - 1 : n;
}

int main() {
    string s; cin >> s;
    int n = s.size();
    cout << fun(s);
}