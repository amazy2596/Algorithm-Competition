// Problem: D. Price Tags
// URL: https://codeforces.com/contest/2144/problem/D
// Author: amazy
// Date: 2025-09-24 18:22:34

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
    i64 n, y;
    cin >> n >> y;
    vector<i64> c(n + 1), cnt(2e5 + 5);
    for (int i = 1; i <= n; i++)
        cin >> c[i], cnt[c[i]]++;

    vector<i64> pre(2e5 + 5);
    for (int i = 1; i <= 2e5; i++)
        pre[i] = pre[i - 1] + cnt[i];
        
    int mx = *max_element(c.begin() + 1, c.end());
    i64 ans = -INF;
    for (i64 x = 2; x <= mx + 1; x++)
    {
        i64 cur = 0;
        i64 need = 0;
        for (int p = 1; p <= (mx + x - 1) / x; p++)
        {
            i64 low = (p - 1) * x + 1, high = min((i64)2e5, p * x);
            need += max(0LL, pre[high] - pre[low - 1] - cnt[p]);
            cur += (pre[high] - pre[low - 1]) * p;
        }
        cur -= need * y;
        ans = max(ans,cur);
    }

    cout << ans << "\n";
}

int main()
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