/*
题意：
    给定一个单链表的头结点 head 和整数 n，
    删除链表的倒数第 n 个结点，并返回删除后的头结点。

思路：
    使用虚拟头结点和快慢指针。

    1. 创建虚拟头结点 dummy，使 dummy.next 指向 head，
       这样删除头结点和删除普通结点可以使用相同的逻辑。

    2. fast 和 slow 都从 dummy 开始。

    3. 先让 fast 向后移动 n 次，
       此时 fast 比 slow 领先 n 个结点。

    4. 当 fast 还没有到达最后一个结点时，
       fast 和 slow 同时向后移动。

    5. 当 fast 到达最后一个结点时，
       slow 正好位于待删除结点的前一个位置。

    6. 让 slow->next 指向 slow->next->next，
       跳过待删除结点。

时间复杂度：O(L) - L 表示链表长度
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // 先让快指针前进 n 步
        while (n--)
            fast = fast->next;

        // 再同时一起走
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *toDel = slow->next;
        slow->next = slow->next->next;
        delete toDel;

        return dummy->next;
    }
};