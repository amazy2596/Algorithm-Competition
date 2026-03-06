// Problem: L3-3 宝藏
// URL: https://ac.nowcoder.com/acm/contest/104429/O
// Author: amazy
// Date: 2026-03-06 23:17:37

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct DSU
{
    vector<int> f, siz;
    int n;

    DSU(int _n) : n(_n), f(_n), siz(_n, 1) 
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
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (siz[rootX] < siz[rootY]) swap(rootX, rootY);

        f[rootY] = rootX;
        siz[rootX] += siz[rootY];
        siz[rootY] = 0;

        return;
    }

    bool connected(int u, int v) { return find(u) == find(v); }
};

void solve()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ans;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int w;
            cin >> w;
            dist[i][j] = w;
            if (w == 0) continue;
            pq.push({w, i, j});
        }
    }

    DSU dsu(n + 1);
    while (!pq.empty())
    {
        auto [w, i, j] = pq.top();
        pq.pop();
        if (dsu.connected(i, j)) continue;
        dsu.merge(i, j);
        int u = min(i, j), v = max(i, j);
        ans.push_back({w, u, v});
    }
    ranges::sort(ans);

    for (auto [w, u, v] : ans) cout << u << " " << v << " " << w << "\n";
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