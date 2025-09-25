// Problem: B. Discounts
// URL: https://codeforces.com/contest/2143/problem/B
// Author: amazy
// Date: 2025-09-25 10:20:37

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(k + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    sort(a.begin() + 1, a.end(), greater<int>());
    sort(b.begin() + 1, b.end());

    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];

    int l = 1;
    i64 ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int r = l + b[i] - 1;
        if (r > n)
        {
            ans += pre[n] - pre[l - 1];
            l = r + 1;
            break;
        }
        else 
        {
            ans += pre[r - 1] - pre[l - 1];
            l = r + 1;
        }
    }
    if (l <= n)
        ans += pre[n] - pre[l - 1];

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