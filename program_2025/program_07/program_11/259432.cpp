#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

// 单点修改 + 前缀最大
struct Fenwick
{
    int n;
    vector<int> a;

    Fenwick(int _n) : n(_n), a(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int k)
    {
        assert(1 <= x && x <= n);
        while (x >= 1 && x <= n)
        {
            a[x] = max(a[x], k);
            x += lowbit(x);
        }
    }

    int query(int r)
    {
        int res = 0;   

        while (r > 0)
        {
            res = max(res, a[r]);
            r -= lowbit(r);
        }

        return res;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), id(n + 1, vector<int>(m + 1));
    vector<int> all;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], all.push_back(a[i][j]);

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            id[i][j] = lower_bound(all.begin(), all.end(), a[i][j]) - all.begin() + 1;

    Fenwick fw(all.size());
    vector<int> f(all.size() + 1);
    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        vector<pair<int, int>> tmp;
        for (int i = 1; i <= n; i++)
        {
            int x = id[i][j];
            int best = fw.query(x - 1);
            tmp.emplace_back(x, best + 1);
        }

        for (auto [x, len] : tmp)
        {
            if (len > f[x])
            {
                f[x] = len;
                fw.update(x, len);
                ans = max(ans, len);
            }
        }
    }

    cout << ans << "\n";
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