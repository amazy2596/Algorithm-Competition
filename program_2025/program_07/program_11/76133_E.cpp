#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;

    if (m < n - 1)
    {
        cout << "-1\n";
        return;
    }

    map<pair<int, int>, int> ans;
    vector<vector<int>> e(n + 1), adj(n + 1);
    sort(a.begin() + 1, a.end());

    e[0].push_back(1);
    for (auto [dist, u] : a)
    {
        if (dist == 0)
            continue;

        auto &vec = e[dist - 1];
        if (vec.empty())
        {
            cout << "-1\n";
            return;
        }

        e[dist].push_back(u);
        int v = vec.back();
        if (u > v)
            swap(u, v);
        ans[{u, v}]++;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (ans.size() == m)
    {
        for (auto [p, _] : ans)
            cout << p.first << " " << p.second << "\n";
        return;
    }

    vector<vector<int>> depth(n + 1);
    auto dfs = [&](auto self, int u, int p, int d) -> void
    {
        depth[d].push_back(u);
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u, d + 1);
        }
    };

    dfs(dfs, 1, 0, 0);
    for (int d = 1; d <= n; d++)
    {
        for (auto u : depth[d])
        {
            for (auto v : depth[d])
            {
                if (u == v)
                    continue;

                int x = min(u, v), y = max(u, v);
                auto key = make_pair(x, y);
                if (ans.find(key) == ans.end())
                {
                    ans[key] = 1;

                    if (ans.size() == m)
                    {
                        for (auto [p, _] : ans)
                            cout << p.first << " " << p.second << "\n";
                        return;
                    }
                }
            }

            for (auto v : depth[d - 1])
            {
                if (u == v)
                    continue;

                int x = min(u, v), y = max(u, v);
                auto key = make_pair(x, y);
                if (ans.find(key) == ans.end())
                {
                    ans[key] = 1;
                    
                    if (ans.size() == m)
                    {
                        for (auto [p, _] : ans)
                            cout << p.first << " " << p.second << "\n";
                        return;
                    }
                }
            }
        }
    }

    if (ans.size() == m)
    {
        for (auto [p, _] : ans)
            cout << p.first << " " << p.second << "\n";
        return;
    }

    cout << "-1\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}