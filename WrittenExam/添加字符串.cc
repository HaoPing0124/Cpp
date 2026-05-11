// 牛牛手里有一个字符串A，羊羊的手里有一个字符串B，B串的长度大于等于A串
// 所以牛牛想把A串变得和B串一样长，这样羊羊就愿意和牛牛一起玩了。
// 而且A串的长度增加到和B串一样长的时候，对应的每一位相等的越多，羊羊就越喜欢。
// 比如"abc"和"abd"对应相等的位数为2，为前两位。
// 牛牛可以在A串的开头或者结尾添加任意字符，使得长度和B串一样。
// 现在问牛牛对A串:添加完字符之后，不相等的位数最少有多少位?
// 例输入：abe cabc 输出：1

// 数据范围小，暴力枚举
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s1; cin >> s1;
    string s2; cin >> s2;

    int len1 = s1.size();
    int len2 = s2.size();

    int mi = len1;
    for(int i = 0; i <= len2 - len1; ++i)
    {
        int count = 0;
        for(int j = 0; j < len1; ++j)
        {
            if(s1[j] != s2[i + j])
                count++;
        }
        mi = min(mi, count);
    }    
    cout << mi;
}