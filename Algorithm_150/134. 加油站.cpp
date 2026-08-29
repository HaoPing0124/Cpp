/*
题意：
    环形道路上有 n 个加油站，
    gas[i] 表示第 i 个加油站可以获得的汽油，
    cost[i] 表示从第 i 个加油站开到第 i + 1 个加油站需要消耗的汽油。

    初始油箱为空，
    求能够顺时针绕环路一周的起始加油站下标。

    如果无法绕行一周，返回 -1。

思路：
    使用贪心算法。

    total 记录整条环路的总剩余油量：
        total += gas[i] - cost[i]

    如果最终 total < 0，
    说明所有加油站提供的总油量小于总消耗，
    无论从哪里出发都不可能绕行一周，返回 -1。

    cur 记录从当前候选起点 start 出发到当前位置的剩余油量。

    遍历到位置 i 时：
        cur += gas[i] - cost[i]

    如果 cur < 0，
    说明从 start 出发无法到达 i + 1。

    此时 start 到 i 之间的任意位置也不可能成为合法起点，
    因此直接令：
        start = i + 1

    并将：
        cur = 0

    重新从下一个位置开始统计。

    遍历结束后，
    如果 total >= 0，
    最终得到的 start 就是合法起点。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include"Algorithm_150.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int cur = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); ++i)
        {
            // 在第 i 个加油站获得汽油，再减去前往下一站的消耗
            int diff = gas[i] - cost[i];

            // 统计整条环路的总剩余油量
            total += diff;

            // 统计从当前候选起点 start 出发的剩余油量
            cur += diff;

            // 当前起点无法继续到达下一站
            if(cur < 0)
            {
                // start ~ i 都不可能作为合法起点
                start = i + 1;
                cur = 0;
            }
        }

        // 总油量不足时无论从哪里出发都不可能完成一圈
        return total < 0 ? -1 : start;
    }
};