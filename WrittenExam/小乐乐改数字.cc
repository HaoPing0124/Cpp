// 小乐乐喜欢数字，尤其喜欢0和1。
// 他现在得到了一个数，想把每位的数变成0或1。
// 如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。
// 请你回答他最后得到的数是多少。

#include "Algorithm.hpp"

using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n; ++i)
    {
        if(s[i] % 2 == 0) s[i] = '0';
        else s[i] = '1';
    }
    cout << stoi(s);
}