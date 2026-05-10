// 给你两个集合，要求{A}+{B}。
// 注:同一个集合中不会有两个相同的元素。
// 输出时按数字升序输出。

#include "Algorithm.hpp"
using namespace std;

// version1 : 额外res数组
int test01() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 9, 0);
    vector<int> b(m + 9, 0);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + m + 1);

    vector<int> res;
    int i = 1, j = 1;
    while(i <= n && j <= m)
    {
        if(a[i] < b[j])
            res.push_back(a[i++]);
        else if(a[i] > b[j])
            res.push_back(b[j++]);
        else
        {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }

    while(i <= n)
        res.push_back(a[i++]);

    while(j <= m)
        res.push_back(b[j++]);

    for(auto &x : res)
        cout << x << ' ';
}


// version2 : 原地合并
int test02() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + m + 1, 0);
    vector<int> b(m + 1, 0);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + m + 1);

    int i = n;
    int j = m;
    int pos = n + m;

    while (i > 0 && j > 0) {
        if (a[i] > b[j]) {
            a[pos] = a[i--];
        } else if (a[i] < b[j]) {
            a[pos] = b[j--];
        } else {
            a[pos] = a[i];
            i--;
            j--;
        }
        pos--;
    }

    while (i > 0) {
        a[pos--] = a[i--];
    }

    while (j > 0) {
        a[pos--] = b[j--];
    }

    int end = (n + m) - pos;
    for (int i = 1; i <= end; ++i) {
        a[i] = a[pos + i];
        cout << a[i] << " ";
    }
    return 0;
}

// version3 : set
int test01() {
    int n, m; 
    cin >> n >> m;

    unordered_set<int> st;
    for(int i = 1; i <= n + m; ++i)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    for(auto &x : st)
        cout << x << " ";
    return 0;
}