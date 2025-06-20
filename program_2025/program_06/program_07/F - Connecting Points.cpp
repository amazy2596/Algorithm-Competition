#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n + 1), siz(n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

struct node
{
    int i, j, dist;

    bool operator<(const node o) const
    {
        return dist > o.dist;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> p(n + 1);
    priority_queue<node> que;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
        for (int j = 1; j < i; j++)
        {
            int d = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
            que.push({i, j, d});
        }
    }

    DSU dsu(2 * n + 1);
    
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            int j = p.size();
            for (int i = 1; i < p.size(); i++)
            {
                auto [x, y] = p[i];
                int d = abs(x - a) + abs(y - b);
                que.push({i, j, d});
            }
            p.push_back({a, b});
        }
        else if (op == 2)
        {
            int mn = inf;
            while (!que.empty())
            {
                auto [i, j, d] = que.top();
                if (dsu.same(i, j))
                    que.pop();
                else 
                    break;
            }

            if (!que.empty())
                mn = que.top().dist;

            while (!que.empty() && que.top().dist == mn)
            {
                auto [i, j, d] = que.top();
                que.pop();

                if (!dsu.same(i, j))
                    dsu.merge(i, j);
            }

            if (mn == inf) cout << "-1\n";
            else cout << mn << "\n";
        }
        else 
        {
            int u, v;
            cin >> u >> v;
            cout << (dsu.same(u, v) ? "Yes\n" : "No\n");
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}