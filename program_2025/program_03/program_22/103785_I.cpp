#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector adj(n + 1, vector<int>());
    for (int s = 2; s <= n; s++)
    {
        int p;
        cin >> p;
        adj[p].push_back(s);
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = k;
    int deep = 1;
    int u = 1;
    while (u <= n)
    {
        if (adj[u].size() == 0)
            break;
        int nxt = 0;
        if (deep % 2 == 0)
        {
            int res = 1e9;
            for (auto v : adj[u])
            {
                if (a[v] < res)
                    res = a[v], nxt = v;
            }
            ans += res;
        }
        else 
        {
            int res = -1e9;
            for (auto v : adj[u])
            {
                if (a[v] > res)
                    res = a[v], nxt = v;
            }
            ans += res;
        }
        u = nxt;
        deep++;
    }

    cout << ans << "\n";
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