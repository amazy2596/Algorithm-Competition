// Problem: E. Split
// URL: https://codeforces.com/contest/2148/problem/E
// Author: amazy
// Date: 2025-09-13 23:16:27

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
    vector<int> a(n + 1);
    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    map<int, int> tar;
    for (auto [key, val] : cnt)
    {
        if (val % k != 0)
        {
            cout << "0\n";
            return;
        }
        tar[key] = val / k;
    }

    int l = 1;
    i64 ans = 0;
    map<int, int> cur;
    for (int r = 1; r <= n; r++)
    {
        cur[a[r]]++;

        while (l < r && cur[a[r]] > tar[a[r]])
        {
            cur[a[l]]--;
            l++;
        }

        ans += (r - l + 1);
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