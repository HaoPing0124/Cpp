/*
题意：
    给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

思路：
    模拟竖式加法，使用 虚拟头节点 配合 双指针同步遍历 来实现。

    1. 引入虚拟头节点 dummy，并用 tail 指针始终指向新链表的末尾，方便依次尾插新节点
    2. 设置 carry 变量记录进位，初始值为 0
    3. 使用 while(l1 || l2) 循环：
       - 使用 ||：即使两个链表长度不同，只要有一个未遍历完，循环就继续；
       - 安全取值：如果当前链表节点不为空，取出其 val，否则用 0 代替；
       - 计算当前位的和：sum = n1 + n2 + carry(进位)；
       - 更新进位 carry = sum / 10，以及当前节点存储的值 sum % 10；
       - 将新节点接在 tail->next，同时将未遍历完的链表指针后移。
    4. 循环结束后，若最高位仍有进位（carry > 0），需在链表末尾追加一个值为 carry 的新节点。

时间复杂度：O(max(m, n))
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0; // 保存进位
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        // l1 和 l2 都遍历完才结束循环
        while (l1 || l2)
        {
            // 为空时就看做是0
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            // 链表的 val + 进位
            int sum = n1 + n2 + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            tail = tail->next;
        }

        if (carry)
            tail->next = new ListNode(carry);

        return dummy->next;
    }
};