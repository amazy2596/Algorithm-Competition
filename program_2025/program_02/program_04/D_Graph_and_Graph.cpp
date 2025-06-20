#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<vector<int>> adj1(n + 1), adj2(n + 1);
    set<pair<int, int>> edges;
    vector<int> good(n + 1);
    int m1;
    cin >> m1;
    for (int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        edges.insert({u, v});
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    int m2;
    cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (edges.count({u, v}) > 0)
            good[u] = good[v] = 1;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<vector<int>> d(n + 1, vector<int>(n + 1, 1e18l));
    d[s1][s2] = 0;
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {s1, s2}});
    while (!st.empty())
    {
        auto [u1, u2] = (*st.begin()).second;
        st.erase(st.begin());

        for (auto v1 : adj1[u1])
        {
            for (auto v2 : adj2[u2])
            {
                int w = abs(v1 - v2);
                if (d[v1][v2] > d[u1][u2] + w)
                {
                    st.erase({d[v1][v2], {v1, v2}});
                    d[v1][v2] = d[u1][u2] + w;
                    st.insert({d[v1][v2], {v1, v2}});
                }
            }
        }
    }

    int ans = 1e18l;
    for (int i = 1; i <= n; i++)
        if (good[i])
            ans = min(ans, d[i][i]);
    
    cout << (ans == 1e18l ? -1 : ans) << "\n";
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