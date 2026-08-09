/*
题意：
    给定一个单链表的头节点 head，
    将链表反转，并返回反转后的头节点。
    例如：
        1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    反转后：
        5 -> 4 -> 3 -> 2 -> 1 -> nullptr
思路：
    使用迭代 + 三指针。
    定义三个指针：
        pre：
            保存已经反转完成的链表。
            初始为空，因为反转后的第一个节点后面应该指向 nullptr。

        cur：
            当前正在处理的节点。
            初始指向 head。

        next：
            暂存 cur 的下一个节点。
            因为修改 cur->next 后，
            原来的后继节点会丢失，所以必须提前保存。

    每次循环执行四步：
        1. 保存下一个节点：
            next = cur->next

        2. 修改当前节点指向：
            cur->next = pre

        3. pre 向前移动：
            pre = cur

        4. cur 向前移动：
            cur = next
    当 cur 为空时，
    说明所有节点已经完成反转。

    此时 pre 就是新的链表头节点。

时间复杂度：O(n)
空间复杂度：O(1)
*/

#include"Algorithm_150.h"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode* cur = head;
        struct ListNode* newNode = NULL;
        while (cur)
        {
            struct ListNode* temp = cur->next;
            cur->next = newNode;
            newNode = cur;
            cur = temp;
        }
        return newNode;
    }
};