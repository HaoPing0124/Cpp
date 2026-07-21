/*
题意：
    给你一个链表数组，每个链表都已经按升序排列。
    请你将所有链表合并到一个升序链表中，返回合并后的链表。

思路：
    使用小根堆。

    1. 将每条非空链表的头结点放入小根堆。

    2. 每次取出堆顶的最小结点，
       将该结点连接到结果链表的末尾。

    3. 如果取出的结点还有下一个结点，
       就将它的 next 放入小根堆。

    4. 当小根堆为空时，说明所有结点都已经合并完成。

时间复杂度：O(N log k)
空间复杂度：O(k)

其中：
    N 表示所有链表的结点总数；
    k 表示链表数量。
*/

#include "Algorithm_150.h"


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        // 将每条非空链表的头结点放入小根堆
        for (auto head : lists)
        {
            if (head)
            {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (!pq.empty())
        {
            // 取出当前最小结点
            ListNode *minNode = pq.top();
            pq.pop();

            // 将当前结点接到结果链表末尾
            tail->next = minNode;
            tail = tail->next;

            // 将当前链表的下一个结点放入堆中
            if (minNode->next)
            {
                pq.push(minNode->next);
            }
        }
        return dummy.next;
    }
};