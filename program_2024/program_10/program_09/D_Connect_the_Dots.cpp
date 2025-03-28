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
            iota(parent.begin(), parent.end(), 0);
            rank.resize(n + 1, 1);
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

        bool connected(int x, int y)
        {
            return find(x) == find(y);
        }
};

const int N = 11;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<pair<int, int>>>> v(N, vector<vector<pair<int, int>>>(N));
    while (m--)
    {
        int a, d, k;
        cin >> a >> d >> k;
        k = min(k, (n - a) / d);
        v[d][a % d].push_back({a, 0});
        v[d][a % d].push_back({a + k * d, 1});
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            auto &vec = v[i][j];
            sort(vec.begin(), vec.end());
            vector<pair<int, int>> res;
            stack<int> s;
            for (int x = 0; x < vec.size(); x++)
            {
                auto [val, f] = vec[x];
                if (f == 1)
                {
                    int last = s.top();
                    s.pop();
                    if (s.empty())   
                        res.push_back({last, val});
                }
                else
                    s.push(val);
            }
            vec = res;
        }
    }
    DSU dsu(n);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (auto [s, e] : v[i][j])
            {
                for (int t = s; t <= e; t += i)
                    dsu.merge(s, t);
            }
        }
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[dsu.find(i)]++;
    cout << mp.size() << "\n";
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