// Problem: 小苯的麦克斯
// URL: https://ac.nowcoder.com/acm/contest/117163/C
// Author: amazy
// Date: 2025-09-25 22:24:20

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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = -inf;
    for (int i = 1; i < n; i++)
    {
        set<int> s;
        int x = a[i - 1], y = a[i];
        if (x > y) swap(x, y);
        if (x == s.size()) s.insert(x);
        if (y == s.size()) s.insert(y);
        int mx = y, mex = s.size();
        ans = max(ans, mx - mex);
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