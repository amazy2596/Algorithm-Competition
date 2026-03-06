// Problem: 无穷无尽的数
// URL: https://ac.nowcoder.com/acm/contest/123788/F
// Author: amazy
// Date: 2026-02-21 11:06:21

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const i64 mod = 998244353;
i64 fast_pow(i64 a, i64 b) 
{
    i64 res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1) res = (1LL * res * a) % mod;
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
    i64 n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    l--, r--;
    i64 len = n;

    i64 bl = l / len;
    i64 br = r / len;
    if (bl == br)
    {
        i64 ans = 0;
        for (i64 i = l % len; i <= r % len; i++)
        {
            ans = (ans * 10 + (s[i] - '0')) % mod;
        }
        cout << ans << "\n";
        return;
    }


    i64 L = (l / len + 1) * len;
    i64 R = (r / len) * len;
    // cout << L << " " << R << "\n";
    i64 k = max((i64)0, (R - L) / len);

    i64 ans = 0;
    i64 tmp = fast_pow(10, len);
    i64 tmp1;
    if (tmp == 1) tmp1 = k % mod;
    else tmp1 = (fast_pow(tmp, k) - 1) % mod * inv((tmp - 1 + mod) % mod) % mod;
    i64 tmp2 = fast_pow(10, k * len + (r - R + 1)) % mod;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = (ans + fast_pow(10, (r - R + 1)) * tmp1 % mod * (s[i] - '0') % mod * fast_pow(10, n - 1 - i) % mod) % mod;
    }
    for (int i = n - 1; i >= l % len; i--)
    {
        ans = (ans + tmp2 * (s[i] - '0') % mod * fast_pow(10, n - 1 - i) % mod) % mod;
    }
    for (int i = (r % len); i >= 0; i--)
    {
        ans = (ans + (s[i] - '0') * fast_pow(10, r % len - i)) % mod;
    }

    cout << ans << "\n";
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