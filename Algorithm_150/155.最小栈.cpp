/*
题意：
    设计一个栈，支持：
        push(x)
            将元素 x 压入栈。
        pop()
            删除栈顶元素。
        top()
            获取栈顶元素。
        getMin()
            获取栈中的最小元素。
    要求所有操作的时间复杂度都是 O(1)。

思路：
    使用两个栈：
    1. 普通栈 _st：
        保存所有插入的元素，
        负责实现 push、pop、top。

    2. 最小栈 _minst：
        保存当前状态下的最小元素。
        规则：
            push：
                如果当前元素小于等于最小栈栈顶，
                说明它可能成为新的最小值，
                将它加入最小栈。

            pop：
                如果普通栈弹出的元素等于最小栈栈顶，
                说明当前最小值被删除，
                最小栈也需要同步弹出。

    保存重复最小值可以保证：
    当一个最小值被弹出时，
    还有另一个相同最小值存在。

时间复杂度：
    push：O(1)
    pop：O(1)
    top：O(1)
    getMin：O(1)

空间复杂度：O(n)
*/

#include "Algorithm_150.h"

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        _st.push(val);
        if (_minst.empty() || val <= _minst.top())
        {
            _minst.push(val);
        }
    }

    void pop()
    {
        if (_st.top() == _minst.top())
        {
            _minst.pop();
        }
        _st.pop();
    }

    int top()
    {
        return _st.top();
    }

    int getMin()
    {
        return _minst.top();
    }

private:
    stack<int> _st;
    stack<int> _minst;
};

// Your MinStack object will be instantiated and called as such:
// MinStack* obj = new MinStack();
// obj->push(val);
// obj->pop();
// int param_3 = obj->top();
// int param_4 = obj->getMin();
