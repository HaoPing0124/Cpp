/*
题意：
    给定一个包含 n + 1 个整数的数组 nums，
    数字都在 [1, n] 范围内。

    根据抽屉原理，至少存在一个重复数字。

    要求：
        找出这个重复数字。

    限制：
        不能修改数组；
        只能使用 O(1) 额外空间。

思路：
    将数组看成一个链表。

    数组下标表示节点，
    nums[i] 表示从节点 i 指向的下一个节点。

    因为数组长度为 n + 1，
    但是数字范围只有 1 ~ n，
    所以一定存在一个重复数字。

    重复数字会导致多个节点指向同一个位置，
    从而形成环。

    使用 Floyd 快慢指针：

    第一阶段：
        slow 每次走一步：
            slow = nums[slow]

        fast 每次走两步：
            fast = nums[nums[fast]]

        两者一定会在环中相遇。

    第二阶段：
        将 slow 放回起点，
        slow 和 fast 每次都走一步。

        两者再次相遇的位置就是环入口，
        也就是重复数字。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // 找到相遇点
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // 找环入口
        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};