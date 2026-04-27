// 现有一个字符串str，输出字符串str中的最长的数字子串。
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) { // 注意 while 处理多个 case
        int n = s.size() - 1;
        int l = 0, r = 1;
        int lens = 0;
        string res;
        while(l <= n && r <= n)
        {
            while(s[l] >= 'a' && s[l] <= 'z') l++;
            r = l + 1;
            while(s[r] >= '0' && s[r] <= '9') r++;
            if(r - l > lens)
            {
                lens = r - l;
                res = s.substr(l, r - l);
            }
            l = r + 1;
        }    
        cout << res;
    }
}