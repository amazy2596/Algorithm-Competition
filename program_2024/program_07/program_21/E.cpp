#include <bits/stdc++.h>
using intt = long long;
using namespace std;

vector<int> a;

class DSU
{
    public:
        vector<int> parent;
        vector<int> size;

        DSU(int n)
        {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n + 1, 1);
        }

        int find(int p)
        {
            if (p != parent[p])
                parent[p] = find(parent[p]);
            return parent[p];
        }

        void merge(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY)
            {
                if (a[rootX] >= a[rootY])
                {
                    parent[rootY] = rootX;
                    size[rootX] += size[rootY];
                    size[rootY] = 0;
                }
                else 
                {
                    parent[rootX] = rootY;
                    size[rootY] += size[rootX];
                    size[rootX] = 0;
                }
            }
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }
    intt ans = 0, mn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        if (dsu.size[i] != 0)
            ans += a[i], mn = min(mn, a[i]);
    }
    ans -= mn;
    cout << ans << "\n";
    return 0;
}