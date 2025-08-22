// Problem: E. Arithmetics Competition
// URL: https://codeforces.com/contest/2132/problem/E
// Author: amazy
// Date: 2025-08-22 13:39:51

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
    int n, m, q;
    cin >> n >> m >> q;
    vector<i64> a(n + 1), pa(n + 1), b(m + 1), pb(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    sort(a.rbegin(), a.rend() - 1);
    sort(b.rbegin(), b.rend() - 1);

    for (int i = 1; i <= n; i++)
        pa[i] = pa[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        pb[i] = pb[i - 1] + b[i];

    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        int l = max(0, z - y), r = min(x, z);
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid + 1] >= b[z - mid])
                l = mid + 1;
            else 
                r = mid;
        }

        cout << pa[l] + pb[z - l] << "\n";
    }
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