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
    int n;
    cin >> n;
    vector<int> to(n + 1), in(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> to[i], in[to[i]]++;

    vector<int> vis(n + 1);
    auto del = [&](auto del, int u) -> void
    {
        vis[u] = 1;
        if (--in[to[u]] == 0)
            del(del, to[u]);
    };

    for (int i = 1; i <= n; i++)
    {
        if (!in[i] && !vis[i])
            del(del, i);
    }

    vector<int> ans(n + 1);
    auto dfs1 = [&](auto dfs, int u, int depth) -> int
    {
        ans[u] = depth;
        if (ans[to[u]])
            return depth;
        else 
            return ans[u] = dfs(dfs, to[u], depth + 1);
    };

    for (int i = 1; i <= n; i++)
    {
        if (in[i] && !ans[i])
            dfs1(dfs1, i, 1);
    }

    auto dfs2 = [&](auto dfs, int u) -> int
    {
        if (ans[u])
            return ans[u];
        else 
            return ans[u] = dfs(dfs, to[u]) + 1;
    };

    for (int i = 1; i <= n; i++)
    {
        if (!in[i] && !ans[i])
            dfs2(dfs2, i);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
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