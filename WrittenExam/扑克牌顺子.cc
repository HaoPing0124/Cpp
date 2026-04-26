// 现在有2副扑克牌，从扑克牌中随机五张扑克牌，我们需要来判断一下是不是顺子。
// 有如下规则:
//     1.A为1,J为11,Q为12,K为13,A不能视为14
//     2.大、小王为0，0可以看作任意牌
//     3.如果给出的五张牌能组成顺子(即这五张牌是连续的)就输出true，否则就输出false。
//     4.数据保证每组5个数字，每组最多含有4个零，数组的数取值为[0，13]
// 要求:空间复杂度O(1)，时间复杂度O(nlogn)，本题也有时间复杂度O(n)的解法

// 时间复杂度：O(nlogn); 空间复杂度：O(1)
#include "Algorithm.hpp"

class Solution1 {
  public:
    bool IsContinuous(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        int n = numbers.size();
        int t = 0;
        for (int i = 0; i < n; ++i) {
            if (numbers[i] == 0) t++;
        }
        for (int i = t + 1; i < n; ++i) {
            if (numbers[i] == numbers[i - 1]) return false;
            t -= numbers[i] - numbers[i - 1] - 1;
            if (t < 0) return false;
        }
        return true;
    }
};


//最佳(位运算)
//时间复杂度：O(n) ;空间复杂度：O(1)

class Solution2 {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() != 5) return false;

        int mask = 0;
        int mn = 14, mx = -1;

        for (int x : numbers) {
            if (x == 0) continue;

            if (mask & (1 << x)) return false;
            mask |= (1 << x);

            mn = min(mn, x);
            mx = max(mx, x);
        }

        if (mx == -1) return true;
        return mx - mn < 5;
    }
};
