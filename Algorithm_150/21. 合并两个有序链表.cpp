/*
题意：
    将两个升序链表合并为一个新的升序链表并返回。
    新链表是通过拼接给定的两个链表的所有节点组成的。

思路：
    使用哨兵节点（Dummy Node）与双指针迭代法。

    1. 引入一个虚拟的头节点 dummy（哨兵节点），用它来统一边界情况，
       免去判断 谁是真正的头节点 的问题
    2. 设立一个 tail 指针，始终指向新链表的末尾（初始指向 dummy）
    3. 比较 list1 和 list2 当前节点的值：
       - 若 list1 的值小，则将 tail->next 指向 list1，并让 list1 后移
       - 若 list2 的值小（或相等），则将 tail->next 指向 list2，并让 list2 后移
    4. 每次接入新节点后，tail 指针都要向后移动一步（tail = tail->next）
    5. 当其中一个链表被遍历完时，退出循环，由于链表是有序的，
       直接将尚未遍历完的那个链表的剩余部分整段接到 tail->next 后面即可

时间复杂度：O(m + n)
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 设立哨兵节点存储结果
        ListNode *dummy = new ListNode(0);
        // 实际移动指针
        struct ListNode *tail = dummy;

        struct ListNode *next1 = list1;
        struct ListNode *next2 = list2;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy->next;
    }
};