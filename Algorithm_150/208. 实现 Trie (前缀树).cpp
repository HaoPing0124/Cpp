/*
题意：
    实现一个 Trie 前缀树，支持以下操作：

    1. insert(word)：
       向前缀树中插入完整字符串 word；

    2. search(word)：
       判断完整字符串 word 是否已经插入；

    3. startsWith(prefix)：
       判断是否存在以 prefix 为前缀的字符串。

思路：
    每个 Trie 结点保存：

        1. children[26]：
           分别指向字符 'a' 到 'z' 对应的孩子结点；

        2. isEnd：
           标记当前结点是否是某个完整单词的结尾。

    插入时：
        按顺序遍历 word 中的每个字符。
        如果对应孩子不存在，就创建新结点；
        最后将末尾结点的 isEnd 标记为 true。

    查询完整单词时：
        按字符逐层向下查找。
        如果路径不存在，返回 false；
        如果路径存在，还必须判断最后结点的 isEnd 是否为 true。

    查询前缀时：
        只要整个 prefix 对应的路径存在，就返回 true，
        不需要判断 isEnd。

时间复杂度：
    insert：O(L)
    search：O(L)
    startsWith：O(L)

空间复杂度：
    O(所有插入字符串的字符总数)

其中 L 表示当前字符串的长度。
*/

#include "Algorithm_150.h"

class Trie
{
private:
    struct TrieNode
    {
        TrieNode *child[26]; // 每层最多 26 个子节点
        bool isEnd;          // 判断单词是否结束

        TrieNode()
            : isEnd(false)
        {
            for (int i = 0; i < 26; ++i)
            {
                child[i] = nullptr;
            }
        }
    };

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *cur = root;
        for (auto &ch : word)
        {
            int idx = ch - 'a';

            // 当前字符对应的孩子不存在，就创建
            if (cur->child[idx] == nullptr)
            {
                cur->child[idx] = new TrieNode();
            }

            // 移动到当前字符对应的结点
            cur = cur->child[idx];
        }

        // 标记完整单词的结尾
        cur->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *cur = root;
        for (auto &ch : word)
        {
            int idx = ch - 'a';

            // 对应路径不存在
            if (cur->child[idx] == nullptr)
            {
                return false;
            }

            cur = cur->child[idx];
        }

        // 路径存在，还要确认这里是完整单词的结尾
        return cur->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (auto &ch : prefix)
        {
            int idx = ch - 'a';

            // 前缀路径不存在
            if (cur->child[idx] == nullptr)
            {
                return false;
            }

            cur = cur->child[idx];
        }

        // 整条前缀路径存在即可
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */