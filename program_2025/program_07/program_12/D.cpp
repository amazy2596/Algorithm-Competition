#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU
{
    int n;
    vector<int> f, siz;
    DSU(int _n) : n(_n), f(_n + 1), siz(_n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }
    
    int find(int x)
    {
        if (x == f[x])
            return x;
        return x = f[x] = find(f[x]);
    };
    
    void merge(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU < rootV)
        {
            f[rootV] = rootU;
            siz[rootU] += siz[rootV];
            siz[rootV] = 0;
        }
        else
        {
            f[rootU] = rootV;
            siz[rootV] += siz[rootU];
            siz[rootU] = 0;
        }
    };
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    for (int i = 0; i <= (1ll << n) - 1; i++)
    {
        vector<int> cur;
        unordered_map<int, int> mp;
        for (int k = 0; k < n; k++)
        {
            if (i >> k & 1)
            {
                cur.push_back(k + 1);
                mp[k + 1]++;
            }
        }

        DSU d(n);
        for (int u : cur)
        {
            for (int v : adj[u])
            {
                if (mp.find(v) != mp.end())
                {
                    d.merge(u, v);
                }
            }
        }

        set<int> s;
        for (int u : cur)
            s.insert(d.find(u));

        if (s.size() != 1)
            continue;

        bool ok = 1;
        for (int j = 0; j < cur.size(); j++)
        {
            DSU tmp(n);
            int cnt = 0;
            for (int k = 0; k < cur.size(); k++)
            {
                if (k == j)
                    continue;
                for (auto v : adj[cur[k]])
                {
                    if (mp.find(v) != mp.end() && v != cur[j])
                    {
                        tmp.merge(cur[k], v);
                        cnt++;
                    }
                }
            }
            cnt /= 2;
            s.clear();
            for (int k = 0; k < cur.size(); k++)
            {
                if (j != k)
                    s.insert(tmp.find(cur[k]));
            }

            if (!(s.size() == 1 && cnt == cur.size() - 2))
            {
                ok = 0;
                break;
            }
        }

        if (ok)
            ans.push_back(cur.size());
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    int siz = ans.size();
    cout << ans[siz - 1] << " " << ans[siz - 2] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}