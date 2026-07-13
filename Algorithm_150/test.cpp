#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long M = 2146516019;
    long long N = 233333333;

    //使用vector在堆区分配内存避免栈溢出
    //933MB的连续内存在本地环境可轻松满足
    vector<int> inv(N + 1);
    inv[1] = 1;

    long long xor_sum = 1;

    for (int i = 2; i <= N; ++i) {
        //线性求逆元核心递推式
        //由于M和M-M/i均接近2e9,乘积约4e18,必须使用1LL强制转换为longlong以防止越界溢出
        inv[i] = 1LL * (M - M / i) * inv[M % i] % M;

        //按位异或累计结果
        xor_sum ^= inv[i];
    }

    cout << xor_sum << endl;

    return 0;
}