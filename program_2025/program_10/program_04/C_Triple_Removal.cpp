// Problem: C. Triple Removal
// URL: https://codeforces.com/contest/2152/problem/C
// Author: amazy
// Date: 2025-10-04 15:47:30

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];

    set<int> s;
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            s.insert(i);
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if ((r - l + 1) % 3 != 0 || (pre[r] - pre[l - 1]) % 3 != 0)
        {
            cout << "-1\n";
            continue;
        }

        auto it = s.lower_bound(l);
        int pos = *it;
        if (it != s.end() && pos + 1 <= r)
            cout << (r - l + 1) / 3 << "\n";
        else 
            cout << (r - l + 1) / 3 + 1 << "\n";
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