/*
题意：
    给你链表的头结点 head
    请将其按 升序 排列并返回 排序后的链表 。

思路：
    使用归并排序。

    1. 使用快慢指针找到链表中点，
       将原链表断开成左右两部分。

    2. 递归地对左右两部分进行排序。

    3. 将两条有序链表合并成一条有序链表。

    当链表为空或只有一个结点时，
    链表已经有序，直接返回。

时间复杂度：O(n log n)
空间复杂度：O(log n)，递归调用栈占用的空间
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
    // 合并两条有序链表
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (left && right)
        {
            // 升序排序
            if (left->val <= right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        // 接上没有遍历完的剩余链表
        tail->next = left ? left : right;

        return dummy->next;
    }

    ListNode *sortList(ListNode *head)
    {
        // 空链表或只有一个结点时，已经有序
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // 使用快慢指针找到链表中点
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // mid 是右半部分的头结点
        ListNode *mid = slow->next;

        // 断开左右两部分
        slow->next = nullptr;

        // 递归排序左右两部分
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        // 合并两条有序链表
        return merge(left, right);
    }
};