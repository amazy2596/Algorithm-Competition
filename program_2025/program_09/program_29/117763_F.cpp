// Problem: 小红的排列构造
// URL: https://ac.nowcoder.com/acm/contest/117763/F
// Author: amazy
// Date: 2025-09-29 11:55:11

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

    bool f = n & 1;
    if (n & 1) n--, k--;
    if (k > n - 1 || k < n / 2 + (n & 1))
    {
        cout << "-1\n";
        return;
    }
    k -= n / 2;

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    reverse(a.begin() + 1, a.end());
    for (int i = 2; i <= n; i++)
    {
        if (k--) swap(a[1], a[i]);
        else break;
    }

    if (f)
    {
        n++;
        a.insert(a.begin() + n - 1, n);
    }

    for (int i = 1; i <= n; i++)
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