#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int sum = 0, cnt = 0, mn = 1e18l;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() <= 1)
            sum += a[i], cnt++;
        mn = min(mn, a[i]);
    }

    if (cnt % 2 == 0)
        cout << sum << "\n";
    else 
        cout << sum + mn << "\n";
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