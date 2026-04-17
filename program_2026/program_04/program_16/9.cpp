#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        d[u]++, d[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1) 
        {
            q.push(i);
            d[i]--;
        }
    }

    while (q.size())
    {
        auto u = q.front();
        q.pop();

        for (auto [v, i] : adj[u])
        {
            if (--d[v] == 1)
            {
                q.push(v);
                d[v]--;
            }
        }
    }

    vector<int> cand;
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, i] : adj[u])
        {
            if (d[u] > 0 && d[v] > 0)
            {
                cand.push_back(i);
            }
        }
    }
    sort(cand.begin(), cand.end());
    cout << cand.back() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}