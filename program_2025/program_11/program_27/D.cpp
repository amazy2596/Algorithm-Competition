#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct block
{
    int l, r, id, blk_id;

    bool operator<(block &o) const
    {
        if (blk_id != o.blk_id) return blk_id < o.blk_id;
        if (blk_id & 1) return r > o.r;
        else return r < o.r;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> dfn(n + 1), rev(n + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        rev[timer] = u;
        dfn[u] = timer++;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);

    int B = sqrt(m);
    vector<block> querys(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        querys[i] = {dfn[x], dfn[y], i, dfn[x] / B};
    }
    sort(querys.begin(), querys.end());

    int mex = 0;
    set<int> s;
    auto add = [&](int u)
    {
        s.insert(a[u]);
        while (s.count(mex)) mex++;
    };
    auto remove = [&](int u)
    {
        s.erase(a[u]);
        if (a[u] < mex) mex = a[u];
    };

    vector<int> ans(n);
    int curL = 0, curR = -1;
    for (auto [L, R, id, blk_id] : querys)
    {
        while (curL > L) add(rev[--curL]);
        while (curR < R) add(rev[++curR]);
        while (curL < L) remove(rev[curL++]);
        while (curR > R) remove(rev[curR--]);

        ans[id] = mex;
    }

    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}

int main()
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