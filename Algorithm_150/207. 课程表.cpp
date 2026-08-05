/*
题意：
    给定 numCourses 门课程和先修关系，
    判断是否可以完成所有课程。

    prerequisites[i] = [a,b]
    表示学习课程 a 前必须先学习课程 b。

思路：
    将课程看成有向图。

    如果存在拓扑排序，
    说明可以完成所有课程。

    使用 BFS 拓扑排序：

    1. 建立邻接表；
    2. 统计每个课程的入度；
    3. 将所有入度为 0 的课程加入队列；
    4. 每学习一个课程，就减少它指向课程的入度；
    5. 如果某课程入度变为 0，加入队列；
    6. 最后统计学习课程数量。

    如果学习数量等于课程总数，
    说明不存在环。

时间复杂度：O(V + E)
空间复杂度：O(V + E)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int cnt = 0;
        vector<vector<int>> graph(numCourses); // 总课程关系表
        vector<int> indegree(numCourses, 0);   // 每门课有多少前置课程
        queue<int> q;

        for (auto &edge : prerequisites)
        {
            int a = edge[0]; // 要学习的课程
            int b = edge[1]; // 前置课程

            // b -> a
            // graph[]:是多少课程的前置课程
            graph[b].push_back(a);

            // a 多了一个前置课程
            indegree[a]++;
        }

        // 找入度为 0 的课程
        for (int i = 0; i < numCourses; ++i)
        {
            // 没有前置课程的课先添加
            if (indegree[i] == 0)
            {
                // 第 i 门课
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            cnt++;

            // 删除 cur 对其他课程的影响
            for (auto &next : graph[cur])
            {
                indegree[next]--;

                // 变成没有前置课程
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        return cnt == numCourses;
    }
};