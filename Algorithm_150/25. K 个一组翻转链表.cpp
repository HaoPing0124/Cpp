/*
题意：
    给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

思路：
    使用虚拟头结点和分组翻转。

    1. 使用 prev 指向当前待翻转组的前一个结点。

    2. 从 prev 开始向后寻找第 k 个结点 tail。
       如果无法找到，说明剩余结点不足 k 个，直接结束。

    3. 保存下一组的起点 nextHead = tail->next。

    4. 翻转区间 [NowHead, nextGroup)。
       其中 NowHead = prev->next。

    5. 翻转完成后：
           原来的 tail 成为当前组的新头结点；
           原来的 NowHead 成为当前组的新尾结点。

       将 prev->next 指向 tail，
       再让 prev 移动到 NowHead，继续处理下一组。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 虚拟头结点
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while (true)
        {
            // 寻找当前组的第 k 个结点
            ListNode *tail = prev;
            for (int i = 0; i < k; ++i)
            {
                tail = tail->next;

                // 剩余结点不足 k 个，保持原顺序
                if (tail == nullptr)
                {
                    return dummy->next;
                }
            }

            ListNode *NowHead = prev->next;  // 当前组的原头结点
            ListNode *NextHead = tail->next; // 下一组的头结点

            // 翻转区间 [nowHead, nextHead)
            ListNode *pre = NextHead;
            ListNode *cur = NowHead;
            while (cur != NextHead)
            {
                ListNode *next = cur->next;
                cur->next = pre;

                pre = cur;
                cur = next;
            }

            prev->next = tail; // tail 是翻转后的新组头
            prev = NowHead;    // nowHead 是翻转后的新组尾
        }
        return nullptr;
    }
};