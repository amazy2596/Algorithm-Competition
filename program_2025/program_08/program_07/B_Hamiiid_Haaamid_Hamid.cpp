#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };



void solve()
{
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    s = " " + s;
    if (x == 1 || x == n)
    {
        cout << "1\n";
        return;
    }

    if (s[x - 1] == '#' || s[x + 1] == '#')
    {
        cout << min(x, n - x + 1) << "\n";
        return;
    }

    int pre = 0, suf = n + 1;
    for (int i = x; i >= 1; i--)
    {
        if (pre == 0 && s[i] == '#')
            pre = i;
    }
    for (int i = x; i <= n; i++)
    {
        if (suf == n + 1 && s[i] == '#')
            suf = i;
    }

    if (pre == 0 && suf == n + 1)
    {
        cout << "1\n";
        return;
    }

    // if (pre == 0)
    // {
    //     cout << min(n - suf + 2, x) << "\n";
    //     return;
    // }

    // if (suf == n + 1)
    // {
    //     cout << min(pre + 1, n - x + 1) << "\n";
    //     return;
    // }

    cout << max(min(pre + 1, n - x + 1), min(n - suf + 2, x)) << "\n";
}

signed main()
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