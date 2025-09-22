// Problem: A. Equal Occurrences
// URL: https://codeforces.com/contest/2146/problem/A
// Author: amazy
// Date: 2025-09-22 16:59:36

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
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]]++;

    map<int, int> rev;
    for (auto [key, val] : mp)
        rev[val]++;

    int ans = 1;
    int sum = 0;
    for (auto it = rev.rbegin(); it != rev.rend(); it++)
    {
        auto [key, val] = *it;
        sum += val;
        ans = max(ans, key * sum);
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