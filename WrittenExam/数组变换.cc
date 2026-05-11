// 牛牛有一个数组，里面的数可能不相等
// 现在他想进行一些操作，使数组的所有数相等。问是否可行?
// 牛牛可以进行的操作:将数组中的任意一个数改为这个数的两倍。
// 该操作可以进行任意次。

// 贪心 + 位运算
// 先找出数组中最大的数，按照这个最大的数一次对每个数求余
// 若等于0 继续比较是否 mx/a[i] 为 2^n 
#include <iostream>
#include <vector>
using namespace std;

int n, mx;
vector<int> a(55);

bool fun() {
    for(int i = 0; i < n; ++i)
    {
        if(mx % a[i]) return false;
        int x = mx / a[i];
        // x & -x 取出x中最小的一位1
        // 因为2 ^ n 在二进制中只能有一个1，所以如果 原数字 - (x & -x) 不为0说明不合法
        if(x - (x & -x)) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
    
    cout << (fun() ? "YES" : "NO");
    return 0;
}