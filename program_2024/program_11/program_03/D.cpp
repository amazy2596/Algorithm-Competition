#include <bits/stdc++.h>
#define int long long
using namespace std;

class DSU
{
    public:
        vector<int> parent, rank, sum;

        DSU(int n, vector<int> data)
        {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n + 1, 1);
            sum = data;
        }

        int find(int x)
        {
            if (x == parent[x])
                return x;
            return parent[x] = find(parent[x]);
        }

        void merge(int x, int y)
        {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY)
            {
                rank[rootX] += rank[rootY];
                rank[rootY] = 0;

                sum[rootX] += sum[rootY];
                sum[rootY] = 0;

                parent[rootY] = rootX;
            }
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
    vector<int> a(n + 1), ne(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], ne[i] = i;
    DSU dsu(n, a);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            int x = dsu.find(l), i = l + 1, last = l;
            while (i <= r)
            {
                dsu.merge(x, i);
                i = ne[i] + 1;
                ne[last] = r;
                last = i;
            }
        }
        else 
        {
            int i;
            cin >> i;
            int x = dsu.find(i);
            cout << fixed << setprecision(10) << dsu.sum[x] * 1.0 / dsu.rank[x] << "\n";
        }
    }
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