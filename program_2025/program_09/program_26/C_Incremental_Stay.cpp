// Problem: C. Incremental Stay
// URL: https://codeforces.com/contest/2151/problem/C
// Author: amazy
// Date: 2025-09-26 11:23:25

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
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];

    vector<i64> pre(2 * n + 1), odd(2 * n + 1), even(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        if (i & 1) odd[i] = odd[i - 1] + a[i];
        else odd[i] = odd[i - 1];
        if (!(i & 1)) even[i] = even[i - 1] + a[i];
        else even[i] = even[i - 1];
    }

    int m = 2 * n;
    for (int k = 1; k <= n; k++)
    {
        i64 ans = 0;
        ans -= pre[k];
        ans += pre[m] - pre[m - k];
        if (k & 1)
        {
            ans += even[m - k] - even[k];
            ans -= odd[m - k] - odd[k];
        }
        else
        {
            ans += odd[m - k] - odd[k];
            ans -= even[m - k] - even[k];
        }

        cout << ans << " ";
    }
    cout << "\n";
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