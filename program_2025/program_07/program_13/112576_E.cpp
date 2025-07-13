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

struct Fenwick 
{
    int n;
    vector<int> a;

    Fenwick(int _n) : n(_n + 1), a(_n + 1, 0) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int k)
    {
        while (x > 0 && x < n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int query(int r)
    {
        int res = 0;
        while (r > 0)
        {
            res += a[r];
            r -= lowbit(r);
        }

        return res;
    }

    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    vector<vector<int>> pos(n + 1);
    Fenwick fw(2 * n);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
        fw.update(i, a[i]);
    }
    
    vector<int> dp(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        int l = min(pos[a[i]][0], pos[a[i]][1]);
        int r = max(pos[a[i]][0], pos[a[i]][1]);
        if (r != i)
            continue;
        dp[i] = max(dp[i], dp[l - 1] + fw.query(l, r));
    }

    cout << dp[2 * n] << "\n";
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