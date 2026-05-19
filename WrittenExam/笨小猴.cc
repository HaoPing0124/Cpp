// 笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。
// 但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大!
// 这种方法的具体描述如下:
// 假设maxn是单词中出现次数最多的字母的出现次数，
// minn是单词中出现次数最少的字母的出现次数
// 如果maxn-minn是一个质数
// 那么笨小猴就认为这是个LuckyWord，这样的单词很可能就是正确的答案。

// 模拟

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i < sqrt(n); ++i)
    {
        if(n % i == 0) return false;
    }
    return true;
}
int main() {
    string s; cin >> s;
    int cnf[26] = { 0 };
    for(auto &x : s)
    {
        cnf[x - 'a']++;
    }
    
    int minn = 1000, maxn = 0;
    for(auto &x : cnf)
    {
        if(x)
        {
            minn = min(minn, x);
            maxn = max(maxn, x);
        }
    }
    if(isPrime(maxn - minn))
    {
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    }
    else 
    {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}
