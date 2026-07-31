/*
题意：
    请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
    实现 LRUCache 类：
        LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
        int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
        void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
    函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

思路：
    使用哈希表和双向链表。

    list 保存 key 和 value，并维护使用顺序：
        链表头部表示最近使用；
        链表尾部表示最久未使用。

    unordered_map 保存：
        key -> 对应的 list 迭代器。

    查询或更新某个 key 时，通过哈希表 O(1) 找到结点，
    再对该节点进行 删除再添加到头结点的方式 将结点 O(1) 移动到链表头部。

    当缓存超过容量时，删除链表尾部结点，
    并同步删除哈希表中的映射。

时间复杂度：
    get：平均 O(1)
    put：平均 O(1)

空间复杂度：O(capacity)
*/

#include "Algorithm_150.h"

class LRUCache
{
private:
    // 双向链表，存储 (key, value)
    // 链表头部表示最近使用，尾部表示最久未使用
    list<pair<int, int>> nodes;

    // key 映射到对应的链表迭代器
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    int capacity;

public:
    // 必须初始化 capacity
    LRUCache(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        auto it = mp.find(key);
        if (it == mp.end())
        {
            return -1;
        }

        // 将当前结点删除再添加到链表头部
        int value = it->second->second;

        // 删除原结点，此时 it 失效
        nodes.erase(it->second);

        // 在链表头部重新创建结点
        nodes.emplace_front(key, value);

        // 必须更新哈希表中的迭代器
        mp[key] = nodes.begin();

        return value;
    }

    void put(int key, int value)
    {
        auto it = mp.find(key);
        // key 已存在
        if (it != mp.end())
        {
            // 删除旧结点
            nodes.erase(it->second);

            // 在头部重新插入更新后的 key-value
            nodes.emplace_front(key, value);

            // 更新哈希表中的迭代器
            mp[key] = nodes.begin();

            return;
        }

        // key 不存在，直接插入头部
        nodes.emplace_front(key, value);
        mp[key] = nodes.begin();

        // 超过容量，删除最久未使用的结点
        if (nodes.size() > capacity)
        {
            auto old = nodes.back().first;
            mp.erase(old);
            nodes.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */