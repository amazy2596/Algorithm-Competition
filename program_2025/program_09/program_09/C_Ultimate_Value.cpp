// Problem: C. Ultimate Value
// URL: https://codeforces.com/contest/2140/problem/C
// Author: amazy
// Date: 2025-09-09 22:51:44

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
    vector<i64> v(n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (i % 2 == 1)
            ans += v[i];
        else 
            ans -= v[i];
    }

    if (n == 1)
    {
        cout << ans << "\n";
        return;
    }

    i64 dist1 = -INF;

    vector<i64> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            pre[i] = max(pre[i - 1], 2 * v[i] - i);
        else 
            pre[i] = max(pre[i], pre[i - 1]);
    }
    for (int i = n ; i >= 1; i--)
    {
        if (i % 2 == 0)
            suf[i] = max(suf[i + 1], 2 * v[i] + i);
        else 
            suf[i] = max(suf[i], suf[i + 1]);
    }

    i64 cur = INF;
    for (int i = 1; i <= n; i += 2)
    {
        cur = min(cur, 2 * v[i] + i);
        dist1 = max(dist1, suf[i + 1] - cur);
    }

    cur = INF;
    for (int i = n - (n % 2 == 0); i >= 1; i -= 2)
    {
        cur = min(cur, 2 * v[i] - i);
        dist1 = max(dist1, pre[i - 1] - cur);
    }

    i64 dist2 = (n % 2 == 1 ? n - 1 : n - 2);
    if (dist1 > dist2)
        ans += dist1;
    else 
        ans += dist2;
    
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