#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, inf), vis(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
            dist[i] = 0, q.push(i);
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (dist[v] == inf)
            {
                dist[v] = min(dist[v], dist[u] + 1);
                q.push(v);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() > 1)
            mx = max(mx, dist[i]);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == mx && adj[i].size() > 1)
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}