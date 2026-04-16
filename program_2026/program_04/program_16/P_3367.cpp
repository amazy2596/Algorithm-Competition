// Problem: 【模板】并查集
// URL: https://www.luogu.com.cn/problem/P3367
// Author: amazy
// Date: 2026-04-16 16:50:43

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

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) dsu.merge(x, y);
        else cout << (dsu.connected(x, y) ? "Y\n" : "N\n");
    }
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