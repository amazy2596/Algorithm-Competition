#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<int> a(n);
    vector adj(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int u, v, len;
        cin >> u >> v >> len;
        adj[u].emplace_back(v, len);
        adj[v].emplace_back(u, len);
    }

    auto dijkstra = [&]()
    {
        vector<int> dist(n, INT32_MAX);
        dist[s] = 0;
        set<pair<int, int>> st = {{0, s}};
        while (!st.empty())
        {
            auto [cur, u] = *st.begin();
            st.erase(st.begin());

            for (auto [v, len] : adj[u])
            {
                if (cur + len < dist[v])
                {
                    if (st.contains({dist[v], v}))
                        st.erase({dist[v], v});
                    dist[v] = cur + len;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist[t];
    };

    int mn = dijkstra();
    
    int mn_dist_num = 0;
    int people = 0;
    vector<int> ans, vis(n);

    auto dfs = [&](auto dfs, int u, int p, int cur, int sum, vector<int> &vec) -> void
    {
        if (cur > mn)
            return;

        if (u == t && cur == mn)
        {
            mn_dist_num++;
            if (sum > people)
            {
                people = sum;
                ans = vec;
            }
        }

        vis[u] = true;
        for (auto [v, len] : adj[u])
        {
            if (v == p)
                continue;
            vec.push_back(v);
            dfs(dfs, v, u, cur + len, sum + a[v], vec);
            vec.pop_back();
        }
        vis[u] = false;
    };

    vector<int> temp = {s};
    dfs(dfs, s, -1, 0, a[s], temp);


    cout << mn_dist_num << " " << people << "\n";
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " \n"[i == ans.size() - 1];
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