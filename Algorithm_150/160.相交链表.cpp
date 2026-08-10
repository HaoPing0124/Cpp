/*
题意：
    给定两个单链表的头结点 headA 和 headB，
    找出并返回两个链表开始相交的第一个结点。

    如果两个链表不相交，返回 nullptr。

    相交是指两个链表从某个结点开始，
    后面的结点地址完全相同，
    不是仅仅结点值相同。

思路：
    使用双指针。

    定义 curA 从 headA 开始遍历，
    curB 从 headB 开始遍历。

    当 curA 走到链表 A 末尾后，
    让它切换到 headB；

    当 curB 走到链表 B 末尾后，
    让它切换到 headA。

时间复杂度：O(m + n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;

        // 两个指针不断向后移动，走到末尾后切换到另一条链表
        while (curA != curB)
        {
            curA = curA == nullptr ? headB : curA->next;
            curB = curB == nullptr ? headA : curB->next;
        }

        // 相交时返回第一个公共结点，不相交时返回 nullptr
        return curA;
    }
};