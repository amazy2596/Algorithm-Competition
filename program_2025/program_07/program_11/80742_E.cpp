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
    vector<vector<int>> adj(n + 1), group(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto self, int u, int p, int red) -> void
    {
        if (s[u] == 'R')
            red = u;
        else 
            group[red].push_back(u);

        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u, red);
        }
    };

    dfs(dfs, 1, 0, 0);

    vector<int> w(n + 1);
    int init = (r >= -l ? r : l);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'W') 
            w[i] = init;
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'W') 
            continue;

        int s0 = 0;
        for (int u : group[i])
            s0 += w[u];

        int a = -r, b = -l;
        int cur = s0;
        if (cur < a)
            cur = a;
        else if (cur > b)
            cur = b;

        int delta = s0 - cur;
        if (delta > 0)
        {
            for (int u : group[i])
            {
                if (delta == 0)
                    break;
                int mx = w[u] - l;
                int tmp = min(mx, delta);
                w[u] -= tmp;
                delta -= tmp;
            }
        }
        else if (delta < 0)
        {
            delta = -delta;
            for (int u : group[i])
            {
                if (delta == 0)
                    break;
                int mx = r - w[u];
                int tmp = min(mx, delta);
                w[u] += tmp;
                delta -= tmp;
            }
        }

        w[i] = -cur;
    }

    for (int i = 1; i <= n; i++)
        cout << w[i] << " ";
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