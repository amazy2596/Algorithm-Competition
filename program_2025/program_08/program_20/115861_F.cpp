// Problem: 小苯的前缀gcd构造
// URL: https://ac.nowcoder.com/acm/contest/115861/F
// Author: amazy
// Date: 2025-08-20 23:31:24

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    if (x < n)
    {
        cout << "-1\n";
        return;
    }

    vector<int> ans(n + 1);
    auto dfs = [&](auto dfs, int idx, int g, int sum) -> bool
    {
        if (idx > n) return sum == x;
        if (idx > 1 && (sum + g * (n - idx + 1) < x || sum + (n - idx + 1) > x)) return false;

        for (int num = g; num >= 1; num--)
        {
            ans[idx] = num;
            int ng = gcd(g, num);
            if (dfs(dfs, idx + 1, ng, sum + ng))
                return true;
        }

        return false;
    };

    for (int i = m; i >= 1; i--)
    {
        ans[1] = i;
        if (dfs(dfs, 2, i, i))
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " \n"[i == n];

            return;
        }
    }

    cout << "-1\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}