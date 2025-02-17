#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class DSU
{
    public:
        vector<int> parent, rank;

        DSU(int n)
        {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n, 1);
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
                parent[rootY] = rootX;
            }
        }

        bool query(int x, int y)
        {
            return find(x) == find(y);
        }
};

void solve()
{
    
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