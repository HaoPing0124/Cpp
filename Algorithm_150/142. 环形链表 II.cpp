/*
题意：
    给定一个链表的头节点 head，返回链表开始入环的第一个节点。
    如果链表无环，则返回 nullptr。

思路：
    使用快慢指针（双指针）法。

    第一阶段：判断是否有环并寻找相遇点
        1. 定义 slow 和 fast 两个指针同时指向 head；
        2. slow 每次走一步，fast 每次走两步；
        3. 如果 fast 指针走到链表末尾（遇到 nullptr），说明链表无环，直接返回 nullptr；
        4. 如果 slow 和 fast 相遇，说明链表有环，记录相遇点并退出循环。

    第二阶段：寻找环的入口点
        根据数学推导
        假设从头节点到环入口的距离为 a
        环入口到相遇点的距离为 b，
        相遇点到环入口的剩余距离为 c。
        当快慢指针相遇时：
            慢指针走的距离：s = a + b
            快指针走的距离：f = a + n(b + c) + b （n 为快指针绕环的圈数）
        因为 fast 的速度是 slow 的两倍，所以 f = 2s：
            a + n(b + c) + b = 2(a + b)
            a = c + (n - 1)(b + c)

        (b + c)只是绕的圈，可以暂时不管 可以看成 a = c
        这说明：如果此时将一个指针重新放回链表开头（head），另一个指针保持在相遇点（slow），
        然后两个指针都以每次一步的速度同时向前推进，当它们再次相遇时，相遇的位置恰好就是环的入口

时间复杂度：O(n) - 第一阶段快慢指针相遇最多走 2n 步，第二阶段最多走 n 步。
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        bool flag = false;

        // 快慢指针找到交点后退出
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            // 如果有交点说明有环
            if (slow == fast)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return nullptr;

        // 将其中一个指针位置设为开头
        fast = head;
        while (fast != slow)
        {
            // 现在同时前进相同步数
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};