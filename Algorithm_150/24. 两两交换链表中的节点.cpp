/*
题意：
    给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
    你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
思路：
    使用虚拟头结点和迭代模拟。
    使用 prev 指向当前两个待交换结点之前的结点。
    设：
        first = prev->next，表示第一个待交换结点；
        second = first->next，表示第二个待交换结点；
        next = second->next，表示下一组链表的起点。
    原来的连接关系是：
        prev → first → second → next
    修改为：
        prev → second → first → next

    每交换完一组以后，让 prev 移动到 first，
    然后继续处理后面的两个结点。

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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        while (pre->next && pre->next->next)
        {
            ListNode *first = pre->next;
            ListNode *second = first->next;
            ListNode *next = second->next;

            pre->next = second;
            second->next = first;
            first->next = next;

            pre = first;
        }
        return dummy->next;
    }
};