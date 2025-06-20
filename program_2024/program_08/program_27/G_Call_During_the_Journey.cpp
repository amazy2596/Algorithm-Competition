#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    vector<vector<int>> adj(n + 1);
    map<pair<int, int>, int> l1s, l2s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        adj[u].push_back(v);
        adj[v].push_back(u);
        l1s[{u, v}] = a, l1s[{v, u}] = a;
        l2s[{u, v}] = b, l2s[{v, u}] = b;
    }

    vector<int> mn(n + 1, INT32_MIN);
    mn[n] = t0;
    set<pair<int, int>> q;
    for (int i = 1; i < n; i++)
        q.insert({INT32_MIN, i});
    q.insert({t0, n});
    while (!q.empty())
    {
        auto top = *q.rbegin();
        q.erase(top);
        int d = top.first, u = top.second;

        for (auto v : adj[u])
        {
            int l1 = l1s[{u, v}], l2 = l2s[{u, v}];
            int d1 = (d - l1 >= t2 || d <= t1) ? d - l1 : d - l2;

            if (d1 == d - l2)
                d1 = max(d1, t1 - l1);

            if (mn[v] < d1)
            {
                q.erase({mn[v], v});
                mn[v] = d1;
                q.insert({mn[v], v});
            }
        }
    }

    cout << (mn[1] >= 0 ? mn[1] : -1) << "\n";

}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}