// 假设链表中每一个节点的值都在0-9之间，那么链表整体就可以代表一个整数。
// 给定两个这种链表，请生成代表两个整数相加值的结果链表。
// 数据范围 : 0 ≤ n, m ≤ 1000000，链表任意值0≤val≤9
// 要求 : 空间复杂度O(n)，时间复杂度O(n)
// 例如:链表1为9->3->7，链表2为6->3，
// 最后生成新的结果链表为1->0->0->0。
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution
{
public:
    ListNode *Reverse(ListNode *head)
    {
        ListNode *newhead = new ListNode(0);
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = newhead->next;
            newhead->next = cur;
            cur = next;
        }
        ListNode *ret = newhead->next;
        delete newhead;
        return ret;
    }

    ListNode *addInList(ListNode *head1, ListNode *head2)
    {
        head1 = Reverse(head1);
        head2 = Reverse(head2);

        int tmp = 0;
        ListNode *cur1 = head1;
        ListNode *cur2 = head2;
        ListNode *res = new ListNode(0);
        ListNode *prev = res;

        while (cur1 || cur2 || tmp)
        {
            if (cur1)
            {
                tmp += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2)
            {
                tmp += cur2->val;
                cur2 = cur2->next;
            }
            prev = prev->next = new ListNode(tmp % 10);
            tmp /= 10;
        }

        ListNode *cur = res->next;
        delete res;
        return Reverse(cur);
    }
};