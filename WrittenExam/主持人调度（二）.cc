// 有 n 个活动即将举办，每个活动都有开始时间与活动的结束时间，
// 第 i 个活动的开始时间是 starti ,第 i 个活动的结束时间是 endi ,
// 举办某个活动就需要为该活动准备一个活动主持人。
// 一位活动主持人在同一时间只能参与一个活动。
// 并且活动主持人需要全程参与活动，换句话说，一个主持人参与了第 i 个活动，
// 那么该主持人在 (starti,endi) 这个时间段不能参与其他任何活动。
// 求为了成功举办这 n 个活动，最少需要多少名主持人。
// 复杂度要求：时间复杂度 O(nlogn) ，空间复杂度 O(n)

// 小根堆
#include "Algorithm.hpp"

class Solution {
public:
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        sort(startEnd.begin(), startEnd.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(startEnd[0][1]);

        for(int i = 1; i < n; ++i)
        {
            int a = startEnd[i][0];
            int b = startEnd[i][1];
            if(a >= pq.top())
            {
                pq.pop();
                pq.push(b);
            }
            else
            {
                pq.push(b);
            }
        }
        return pq.size();
    }
};