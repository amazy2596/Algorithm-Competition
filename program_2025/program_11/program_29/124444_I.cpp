// Problem: 天酱的 min * max
// URL: https://ac.nowcoder.com/acm/contest/124444/I
// Author: amazy
// Date: 2025-11-29 11:25:57

// Problem: 天酱的 min * max
// URL: https://ac.nowcoder.com/acm/contest/124444/I
// Author: amazy
// Date: 2025-11-29 11:18:14

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const i64 mod = 1e9 + 7;
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
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<i64> b(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        b[i] = (a[i] * inv(fast_pow(2, i))) % mod;
        pre[i] = (pre[i - 1] + b[i]) % mod;
    }
    // i < j
    // a[i] * a[j] * 2 ^ (j - i - 1);
    i64 ans = 0;
    for (int j = 1; j <= n; j++)
    {
        ans = (ans + a[j] * a[j]) % mod;
        ans = (ans + a[j] * fast_pow(2, j - 1) % mod * pre[j - 1]) % mod;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}