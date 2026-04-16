// Problem: L3-1 村庄通信
// URL: https://ac.nowcoder.com/acm/contest/130247/M
// Author: amazy
// Date: 2026-03-14 16:15:41

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct DSU 
{
    int n;
    vector<int> f, siz;
    DSU(int _n) : f(_n + 1), siz(_n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (siz[x] < siz[y]) swap(x, y);

        f[y] = x;
        siz[x] += siz[y];
        siz[y] = 0;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

struct node
{
    int w, u, v;
    bool operator<(const node &o) const 
    {
        return w > o.w;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<tuple<int, int, int>> e(m);
    for (auto &[u, v, w] : e) cin >> u >> v >> w;
    for (int i = 1; i <= n; i++) e.push_back({0, i, a[i]});
    priority_queue<node> pq;
    for (int i = 0; i < e.size(); i++)
    {
        auto [u, v, w] = e[i];
        pq.push({w, u, v});
    }

    DSU dsu(n + 1);
    i64 ans = 0;
    while (!pq.empty())
    {
        auto [w, u, v] = pq.top();
        pq.pop();
        if (dsu.connected(u, v)) continue;
        dsu.merge(u, v);
        ans += w;
    }

    for (int i = 0; i < m; i++)
    {
        auto [u, v, w] = e[i];
        pq.push({w, u, v});
    }

    DSU dsu1(n + 1);
    i64 ans1 = 0;
    int cnt1 = 0;
    while (!pq.empty())
    {
        auto [w, u, v] = pq.top();
        pq.pop();
        if (dsu1.connected(u, v)) continue;
        dsu1.merge(u, v);
        ans1 += w;
        cnt1++;
    }

    if (cnt1 != n - 1) ans1 = 4e18;

    cout << min(ans, ans1) << "\n";
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