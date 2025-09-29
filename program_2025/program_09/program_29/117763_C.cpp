// Problem: 小红抽卡
// URL: https://ac.nowcoder.com/acm/contest/117763/C
// Author: amazy
// Date: 2025-09-29 11:08:16

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
    i64 n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    k %= x;
    int mid = x - k + 1;
    for (int i = mid; i <= x; i++)
        cout << a[i] << " ";
    for (int i = 1; i < mid; i++)
        cout << a[i] << " ";
    for (int i = x + 1; i <= n; i++)
        cout << a[i] << " ";
}

int main()
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