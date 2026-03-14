// Problem: 小红打牌
// URL: https://ac.nowcoder.com/acm/contest/125954/D
// Author: amazy
// Date: 2026-03-10 11:39:20

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const int N = 2e5 + 5;
const i64 mod = 998244353;
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

struct Comb 
{
    vector<int> fact; 
    vector<int> ifact;

    Comb(int n = 2e6) { init(n); }

    void init(int n) 
    {
        fact.resize(n + 1);
        ifact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) 
            fact[i] = 1LL * fact[i - 1] * i % mod;
            
        ifact[n] = inv(fact[n]);
        for (int i = n - 1; i >= 0; i--) 
            ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
    }

    int fast_pow(int a, int b) 
    {
        int res = 1;
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

    int inv(int x) { return fast_pow(x, mod - 2); }
    
    int C(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        return (((1LL * fact[n] * ifact[m]) % mod) * ifact[n - m]) % mod;
    }

    int A(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        return (1LL * fact[n] * ifact[n - m]) % mod;
    }

    i64 lucas(i64 n, i64 m) 
    {
        // 公式: lucas(n / p, m / p) * C(n % p, m % p) 
        // mod < 1e5
        if (m == 0) return 1;
        return lucas(n / mod, m / mod) * C(n % mod, m % mod) % mod;
    }
} Comb;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(N);
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

    i64 ans = 0;
    int x = 0, y = 0; 
    for (int i = 1; i < N; i++) x += (cnt[i] >= 2), y += (cnt[i] >= 4);
    for (int i = 2; i < N; i++)
    {
        if (cnt[i - 1] >= 3 && cnt[i] >= 3)
        {
            if (cnt[i - 1] >= 4 && cnt[i - 1] - 3 < 4) y--;
            if (cnt[i - 1] >= 2 && cnt[i - 1] - 3 < 2) x--;
            if (cnt[i] >= 4 && cnt[i] - 3 < 4) y--;
            if (cnt[i] >= 2 && cnt[i] - 3 < 2) x--;

            ans = (ans + y + Comb.C(x, 2)) % mod;

            if (cnt[i - 1] >= 4 && cnt[i - 1] - 3 < 4) y++;
            if (cnt[i - 1] >= 2 && cnt[i - 1] - 3 < 2) x++;
            if (cnt[i] >= 4 && cnt[i] - 3 < 4) y++;
            if (cnt[i] >= 2 && cnt[i] - 3 < 2) x++;
        }
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