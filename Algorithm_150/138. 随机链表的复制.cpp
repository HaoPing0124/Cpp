/*
题意：
    给定一个带有 next 指针和 random 指针的链表，
    创建该链表的深拷贝。

    复制链表中的所有结点都必须是新创建的结点，
    并且复制结点的 next 和 random 都必须指向复制链表中的结点。

思路：
    使用结点穿插法。

    1. 在每个原结点后面创建并插入对应的复制结点。

       原链表：
           A -> B -> C

       穿插后：
           A -> A' -> B -> B' -> C -> C'

    2. 设置复制结点的 random 指针。

       原结点 cur 对应的复制结点是 cur->next。
       如果 cur->random 不为空，那么该 random 指向结点的复制结点
       就是 cur->random->next。

    3. 从穿插链表中提取复制结点，同时恢复原链表。

时间复杂度：O(n)
空间复杂度：O(1)，不计算返回的新链表占用的空间
*/

#include "Algorithm_150.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        // 1.在每个原结点后面插入对应的复制结点
        while(cur)
        {
            // 构建拷贝链表 位置在原链表的next
            Node* copy = new Node(0);
            copy->val = cur->val;

            // 拷贝链表的 next 指向原链表的 next
            // 原链表 next 指向拷贝链表
            copy->next = cur->next;
            cur->next = copy;
            
            cur = copy->next;
        }

        // 2.设置复制结点的 random 指针
        cur = head;
        while(cur)
        {
            Node* copy = cur->next;
            // 拷贝链表的 random 等于 原链表 random 的 next
            copy->random = cur->random ? cur->random->next : cur->random;

            cur = copy->next;
        }

        // 3.提取出拷贝链表并将原表恢复
        Node* copyhead = NULL, *copytail = NULL;
        cur = head;
        while(cur)
        {
            Node* copy = cur->next;
            Node* next = copy->next;

            if(copyhead == NULL)
            {
                copyhead = copytail = copy;
            }
            else
            {
                copytail->next = copy;
                copytail = copy;
            }

            cur->next = next;   // 恢复原链表
            cur = next;
        }
        return copyhead;
    }
};