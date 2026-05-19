// 有 n 个活动即将举办，每个活动都有开始时间与活动的结束时间，
// 第 i 个活动的开始时间是 starti ,第 i 个活动的结束时间是 endi ,
// 举办某个活动就需要为该活动准备一个活动主持人。
// 一位活动主持人在同一时间只能参与一个活动。
// 并且活动主持人需要全程参与活动，换句话说，一个主持人参与了第 i 个活动，
// 那么该主持人在 (starti,endi) 这个时间段不能参与其他任何活动。
// 请问一个只有一个主持人能否举办全部活动。

// 排序
#include "Algorithm.hpp"

class Solution {
public:
    bool hostschedule(vector<vector<int> >& schedule) {
        sort(schedule.begin(), schedule.end());
        
        int n = schedule.size();
        for(int i = 1; i < n; ++i)
        {
            if(schedule[i][0] < schedule[i - 1][1])
                return false;
        }
        return true;
    }
};