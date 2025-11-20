#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
const i64 mod = 1e9 + 7;
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
            
        ifact[n] = fast_pow(fact[n], mod - 2);
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
// snippet-end

void solve()
{
    
}

signed main()
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