// dd作为体操队队长，在给队员们排队形，体操队形为一个单独的纵列
// 体操队有n个同学，标号为1~n，对于(1≤i≤n)号队员，会有一个诉求(1≤ai≤n)
// 表示他想排在a[i]号队员前面，当a[i]=i时，我们认为他没有位置需求，随便排哪儿都行
// dd想知道有多少种队形方案，可以满足所有队员的要求。

// DFS
#include<iostream>
using namespace std;

const int N = 15;
int n, res;
int a[N];
bool vis[N];

void dfs(int pos)
{
    // 位置选满了说明过程没有被剪枝 都合法
    if(n + 1 == pos)
    {
        res++;
        return;
    }

    // i 代表第 i 个人
    for(int i = 1; i <= n; ++i)
    {
        if(vis[i]) continue;    // 第i个人已经被选了
        if(vis[a[i]]) continue; // 第i个人想选的位置已经被选了 剪枝

        // 到这一定有合法位置
        // 先选上这第i个人，然后开始dfs搜索这个位置选这第i个人时，所有的可能   
        vis[i] = true;
        dfs(pos + 1);
        // 恢复现场
        vis[i] = false;
    }
}

int main()
{    
    cin >> n; 
    for(int i = 1; i <= n; ++i) cin >> a[i];
    
    dfs(1);
    
    cout << res << endl;
    return 0;
}