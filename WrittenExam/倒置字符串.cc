// 将一句话的单词进行倒置，标点不倒置。
// 比如"I like beijing."，经过处理后变为:"beijing. like I"。
// 字符串长度不超过100。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<string> res;

    int start = 0;
    // 寻找第一个空格
    int pos = s.find(' ', start);

    // 只要能找到空格，就一直切
    while (pos != string::npos) {
        // 计算当前单词的长度：空格位置 - 起始位置
        int len = pos - start;

        // 只有长度大于 0 才切（防止两个连续空格的情况）
        if (len > 0)
            res.push_back(s.substr(start, len));

        // 下一个单词的起点是当前空格的后一位
        start = pos + 1;
        // 从新的起点开始找下一个空格
        pos = s.find(' ', start);
    }

    // 循环结束后，处理最后一个单词（因为它后面没空格）
    if (start < s.length()) {
        res.push_back(s.substr(start));
    }

    // 倒序输出
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i];
        if (i != 0) cout << " ";
    }
}