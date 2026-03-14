// Problem: E - Simple Division
// URL: https://atcoder.jp/contests/abc448/tasks/abc448_e
// Author: amazy
// Date: 2026-03-13 12:21:20

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

i64 mod = 10007;
i64 fast_pow(i64 a, i64 b) 
{
    i64 res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x) 
{
    return fast_pow(x, mod - 2);
}

void solve()
{
    int k, m;
    cin >> k >> m;
    mod *= 9 * m;
    vector<char> ch(k + 1);
    vector<i64> l(k + 1), pre(k + 2);
    for (int i = 1; i <= k; i++) cin >> ch[i] >> l[i], pre[i] = pre[i - 1] + l[i];

    i64 ans = 0;
    for (int i = 1; i <= k; i++)
    {
        i64 base = fast_pow(10, pre[k] - pre[i]) % mod;
        i64 cur = (ch[i] - '0') * (fast_pow(10, l[i]) - 1 + mod) % mod;
        ans = (ans + cur % mod * base) % mod;
    }

    cout << ans / 9 / m << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}