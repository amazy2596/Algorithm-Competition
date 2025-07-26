#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int l, r;
    cin >> l >> r;

    unordered_map<int, int> memo;
    auto T = [&](int n) -> int
    {
        if (memo.find(n) != memo.end())
            return memo[n];
            
        int l = 1;
        int res = 0;
        while (l <= n)
        {
            int v = n / l;
            int r = n / v;

            res += (r - l + 1) * v;
            l = r + 1;
        }
        return memo[n] = res;
    };

    auto dfs = [&](auto dfs, int n, int p) -> int
    {
        if (n == 0) return 0ll;

        return dfs(dfs, n / p, p) + T(n / p);
    };

    int fact2 = dfs(dfs, r, 2) - dfs(dfs, l - 1, 2);
    int fact5 = dfs(dfs, r, 5) - dfs(dfs, l - 1, 5);

    cout << min(fact2, fact5) << "\n";
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