// Problem: E1. Maple and Tree Beauty (Easy Version)
// URL: https://codeforces.com/contest/2139/problem/E1
// Author: amazy
// Date: 2025-09-09 21:18:22

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
    vector<int> fa(n + 1), deep(n + 1), cnt(n + 1), is_leaf(n + 1, 1);
    cnt[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        is_leaf[fa[i]] = 0;
        deep[i] = deep[fa[i]] + 1;
        cnt[deep[i]]++;
    }

    int mn = inf;
    for (int i = 1; i <= n; i++)
    {
        if (is_leaf[i]) mn = min(mn, deep[i]);
    }

    // vector<int> dp(n + 1);
    // dp[0] = 1;
    const int N = 2e5 + 5;
    bitset<N> dp;
    dp.set(0, 1);
    int sum = 0;
    for (int i = 0; i <= mn; i++)
    {
        sum += cnt[i];
        dp |= (dp << cnt[i]);
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[i] && i <= k && sum - i <= n - k)
        {
            cout << mn + 1 << "\n";
            return;
        }
    }

    cout << mn << "\n";
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