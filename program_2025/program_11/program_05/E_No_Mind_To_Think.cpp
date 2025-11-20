// Problem: E. No Mind To Think
// URL: https://codeforces.com/contest/2154/problem/E
// Author: amazy
// Date: 2025-11-05 09:01:27

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
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    i64 ans = pre[n];
    for (i64 i = 1; i <= n; i++)    
    {
        i64 l = 1, r = min(n - i, i - 1) + 1;
        while (l < r)
        {
            i64 mid = l + r >> 1;

            i64 left = min((mid - 1) * k, i - 1) + 1;
            i64 right = min(mid * k, i - 1);
            i64 cost = pre[right] - pre[left - 1] + a[i + mid];
            if (cost <= 1LL * a[i] * (right - left + 1 + 1))
                l = mid + 1;
            else 
                r = mid;
        }
        if (--l == 0) continue;

        i64 right = min(k * l, i - 1);
        i64 len = right + l;
        i64 cost = 1LL * a[i] * len - (pre[right] + pre[i + l] - pre[i]);
        ans = max(ans, pre[n] + cost);
    }

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