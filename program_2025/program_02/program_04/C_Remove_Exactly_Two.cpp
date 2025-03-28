#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    vector<int> d(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }

    int ans = 1;
    int mx = 0;
    vector<int> sd = d;
    sort(sd.begin(), sd.end());

    for (int u = 1; u <= n; u++)
    {
        ans = d[u];
        vector<int> temp;
        for (int v : adj[u])
            temp.push_back(d[v]);

        temp.push_back(d[u]);
        sort(temp.rbegin(), temp.rend());

        vector<int> rem;
        int cnt = -1;

        for (int d : temp)
        {
            if (sd.back() == d)
            {
                rem.push_back(d);
                sd.pop_back();
            }
        }

        reverse(rem.begin(), rem.end());

        if (!sd.empty())
            cnt = max(cnt, sd.back());
        for (int v : adj[u])
            cnt = max(cnt, d[v] - 1);
        
        for (int d : rem)
            sd.push_back(d);
        // sort(sd.begin(), sd.end());

        mx = max(mx, ans + cnt - 1);
    }

    cout << mx << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}