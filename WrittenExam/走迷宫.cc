// 给定一个n * m的网格。
// 你从起点(as,ys)出发，每一次可以向上、下、左、右移动一步(若不超出边界)。
// 某些格子上存在障碍物，无法经过。
// 求从(xs,ys)移动到终点(xt，yt)的最少步数;
// 若无法到达，输出-1。

// BFS
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

const int N = 1010;
char arr[N][N];
int dist[N][N];
queue<pair<int, int>> q;
int n, m;
int x1, y1, x2, y2;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs()
{
    if(arr[x2][y2] == '*') return -1;

    memset(dist, -1, sizeof(dist));
    q.push({x1, y1});
    dist[x1][y1] = 0;
    
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int x = a + dx[i];
            int y = b + dy[i];
            
            if(x >= 1 && x <= n && y >= 1 && y <= m && arr[x][y] == '.' && dist[x][y] == -1)
            {
                q.push({x, y});
                dist[x][y] = dist[a][b] + 1;
                if(x == x2 && y == y2) return dist[x2][y2];
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << bfs() << '\n';
    return 0;
}