#include <bits/stdc++.h>
using intt = long long;
using namespace std;

struct node {
    int idx, step;
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n + 1), ans(n + 1, INT32_MAX), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    queue<node> q;
    q.push({a, 0});
    ans[a] = 0;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        int idx = top.idx, step = top.step;
        ans[idx] = min(ans[idx], step);
        if (vis[idx])
            continue;
        vis[idx] = 1;
        if (idx + v[idx] >= 1 && idx + v[idx] <= n)
            q.push({idx + v[idx], min(step + 1, ans[idx + v[idx]])});
        if (idx - v[idx] >= 1 && idx - v[idx] <= n)
            q.push({idx - v[idx], min(step + 1, ans[idx - v[idx]])});
    }
    if (ans[b] != INT32_MAX)
        cout << ans[b];
    else 
        cout << -1;
    return 0;
}