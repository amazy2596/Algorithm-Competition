#include <bits/stdc++.h>
#define int long long
using namespace std;

class DSU
{
    public:
        vector<int> parent, rank;
        DSU(int n)
        {
            parent.resize(n + 1);
            rank.resize(n + 1, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x)
        {
            if (parent[x] != x)
                return parent[x] = find(parent[x]);
            return x;
        }

        void merge(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY)
            {
                if (rank[rootX] < rank[rootY])
                    swap(rank[rootX], rank[rootY]);
                rank[rootX] += rank[rootY];
                rank[rootY] = 0;
                parent[rootY] = rootX;
            }
        }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    vector<int> color(n + 1), size(n + 1, 1);
    iota(color.begin(), color.end(), 0);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, c;
            cin >> x >> c;
            int root = dsu.find(x);
            int groupSize = dsu.rank[root];

            size[color[root]] -= groupSize;
            color[root] = c;
            size[color[root]] += groupSize;

            if (root - 1 >= 1 && color[dsu.find(root - 1)] == color[root])
                dsu.merge(root - 1, root);
            if (root + groupSize <= n && color[dsu.find(root + groupSize)] == color[root])
                dsu.merge(root, root + groupSize);
        }
        else
        {
            int c;
            cin >> c;
            cout << size[c] << "\n";
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