// 给定一个包含n个点m条边的有向无环图，求出该图的拓扑序。
// 若图的拓扑序不唯一，输出任意合法的拓扑序即可。
// 若该图不能拓扑排序，输出一1。

// 模版 BFS
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 2e5 + 9;
vector<vector<int>> edgs(N); // edgs[i] 表示 i 这个点所连接的边的信息
vector<int> in(N);           // 统计入度信息
vector<int> res;             // 记录结果

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        edgs[a].push_back(b);
        in[b]++;
    }

    // 将入度为0的点加入队列
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 0)
            q.push(i);
    }

    // 按照队列顺序加入到res中
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        res.push_back(a);

        // 添加后将该点在图中删除（将该点的 出度点 的入度 都--）
        for (auto b : edgs[a])
        {
            if (--in[b] == 0) // 若--后入度为0 说明可以作为下一个点 加入队列
                q.push(b);
        }
    }

    if (res.size() == n)
    {
        // for (int i = 0; i < n - 1; ++i) {
        //     cout << res[i] << ' ';
        // }
        // cout << res[n - 1];
        for (int i = 0; i < n; ++i)
            cout << res[i] << ' ';
    }
    else
    {
        cout << -1 << '\n';
    }
}