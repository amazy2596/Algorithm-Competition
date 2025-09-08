// Problem: B. Cake Collection
// URL: https://codeforces.com/contest/2139/problem/B
// Author: amazy
// Date: 2025-09-08 22:36:59

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
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());

    i64 ans = 0;
    i64 rem = m - m / n * n;
    i64 t = 1;
    for (int i = n - rem + 1; i <= n; i++)
    {
        ans += t * a[i];
        t++;
    }
    for (int i = 1; i <= n && t <= m; i++)
    {
        if (t <= m)
        {
            if (i < n - rem + 1)
                ans += t * a[i];
            else 
                ans += n * a[i];
            t++;
        }
    }

    m -= (t - 1);
    ans += m * accumulate(a.begin() + 1, a.end(), 0LL);
    cout << ans << "\n";
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