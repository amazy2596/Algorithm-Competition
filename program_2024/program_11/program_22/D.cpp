#include <bits/stdc++.h>
#define int long long
using namespace std;

class DSU
{
    public:
        int n;
        vector<int> p, rank;

        DSU(int size)
        {
            n = size;
            p.resize(n + 1);
            iota(p.begin(), p.end(), 0);
            rank.resize(n + 1, 0);
        }

        int find(int x)
        {
            if (x == p[x])
                return x;
            return p[x] = find(p[x]);
        }

        void merge(int x, int y)
        {
            if (x > y)
                swap(x, y);
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return;
            rank[rootX] += rank[rootY];
            rank[rootY] = 0;
            p[rootY] = rootX;
        }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    DSU dsu(n);
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        dsu.merge(i, j);
    }
    map<int, map<int, int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int key = dsu.find(i);
        mp[key][a[i]]++;
    }
    int ans = 0;
    for (auto [key, mpp] : mp)
    {
        int mx = 0, sum = 0;
        for (auto [k, v] : mpp)
            mx = max(mx, v), sum += v;
        ans += sum - mx;
    }
    cout << ans << "\n";
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