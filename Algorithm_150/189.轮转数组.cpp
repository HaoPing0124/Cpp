/*
题意：
    给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置。
    例如：
        nums = [1,2,3,4,5,6,7]
        k = 3
    轮转后：
        [5,6,7,1,2,3,4]

思路：
    使用三次反转。

    首先使用 k %= n，将 k 转换为真正需要轮转的位置数。例如数组长度为 7，向右轮转 10 次，等价于向右轮转 3 次。
    第一次反转整个数组，使原数组后面的 k 个元素移动到前面，但这两部分内部顺序都是反的。
    第二次反转前 k 个元素，恢复轮转到前面的这一部分的正确顺序。
    第三次反转剩余的 n - k 个元素，恢复后一部分的正确顺序。

    例如：
        [1,2,3,4,5,6,7]
        整体反转后：[7,6,5,4,3,2,1]
        前 k 个反转：[5,6,7,4,3,2,1]
        后面部分反转：[5,6,7,1,2,3,4]

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (len == 0) return;

        // k 可能大于数组长度，先转换为真正需要轮转的位置数
        k %= len;
        if (k == 0) return;

        reverse(nums.begin(), nums.begin() + (len - k));
        reverse(nums.begin() + (len - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};