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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;

    s = " " + s;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> val(n + 1);
    auto dfs1 = [&](auto self, int u, int p) -> vector<int>
    {
        vector<int> cur;

        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            auto res = self(self, v, u);
            cur.insert(cur.end(), res.begin(), res.end());
        }

        if (s[u] == 'W')
            cur.push_back(u);
        else 
        {
            while (cur.size() >= 2)
            {
                int x = cur.back();
                cur.pop_back();
                int y = cur.back();
                cur.pop_back();

                val[x] = l, val[y] = r;
            }

            if (!cur.empty())
            {
                val[u] = r;
                val[cur.back()] = l;
                cur.pop_back();
            }
            else 
                cur.push_back(u);
        }

        return cur;
    };

    auto cur = dfs1(dfs1, 1, 0);
    while (cur.size() >= 2)
    {
        int x = cur.back();
        cur.pop_back();
        int y = cur.back();
        cur.pop_back();

        val[x] = l, val[y] = r;
    }

    for (int i = 1; i <= n; i++)
        cout << val[i] << " ";
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