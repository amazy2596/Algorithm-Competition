#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k, a, b, x, y;
    cin >> n >> k >> a >> b >> x >> y;
    a--, b--;

    vector<int> vis(n), dist(n, 1e9);
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        if (vis[top])
            continue;
        vis[top] = 1;

        int next = (top + x) % n;
        dist[next] = min(dist[next], dist[top] + 1);
        q.push(next);
        next = (top - y + n) % n;
        dist[next] = min(dist[next], dist[top] + 1);
        q.push(next);
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (k >= 1 && (i + n / 2) % n == b)
            ans = min(ans, dist[i] + 1);
    }
    ans = min(ans, dist[b]);
    cout << (ans == 1e9 ? -1 : ans) << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}