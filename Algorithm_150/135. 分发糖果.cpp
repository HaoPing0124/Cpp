/*
题意：
    有 n 个孩子站成一排，ratings[i] 表示第 i 个孩子的评分。

    给每个孩子分发糖果，要求：
        1. 每个孩子至少得到 1 个糖果；
        2. 如果一个孩子的评分比相邻孩子高，
           那么这个孩子得到的糖果也必须更多。

    求满足要求时需要分发的最少糖果总数。

思路：
    使用贪心算法，两次遍历。

    创建 candy 数组，
    candy[i] 表示第 i 个孩子得到的糖果数量，
    所有孩子先初始化为 1。

    第一次从左向右遍历：
        如果 ratings[i] > ratings[i - 1]，
        说明当前孩子评分比左边孩子高，
        当前孩子至少要比左边多一个糖果：

            candy[i] = candy[i - 1] + 1

    这样保证了所有孩子与左边邻居之间的要求。

    第二次从右向左遍历：
        如果 ratings[i] > ratings[i + 1]，
        说明当前孩子评分比右边孩子高，
        当前孩子至少要比右边多一个糖果。

        但第一次遍历已经可能给当前孩子分配了更多糖果，
        所以不能直接覆盖，而要取最大值：

            candy[i] = max(candy[i], candy[i + 1] + 1)

    两次遍历完成后，
    每个孩子同时满足左边和右边的要求。

    最后累加 candy 中所有糖果数量。

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include"Algorithm_150.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // 每个孩子至少有一个糖果
        vector<int> candy(n, 1);

        // 从左向右，保证评分高于左边时糖果也更多
        for(int i = 1; i < n; ++i)
        {
            if(ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // 从右向左，保证评分高于右边时糖果也更多
        for(int i = n - 2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1])
            {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int res = 0;

        for(const auto &x : candy)
        {
            res += x;
        }

        return res;
    }
};