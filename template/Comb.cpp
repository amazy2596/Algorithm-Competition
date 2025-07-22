#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int mod = mod1;
struct Comb 
{
    int max_n;          
    vector<int> fact; 
    vector<int> ifact; 
    vector<int> p2;

    Comb(int n = 2e6 + 5) : max_n(n)
    {
        fact.resize(max_n + 1);
        ifact.resize(max_n + 1);
        p2.resize(max_n + 1);

        p2[0] = 1;
        for (int i = 1; i <= max_n; i++) p2[i] = (p2[i - 1] * 2) % mod;

        fact[0] = 1;
        for (int i = 1; i <= max_n; i++) fact[i] = (fact[i - 1] * i) % mod;
        
        ifact[max_n] = fast_pow(fact[max_n], mod - 2);
        for (int i = max_n - 1; i >= 0; i--) ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    }

    int fast_pow(int a, int b) 
    {
        int res = 1;
        a %= mod;
        while (b) 
        {
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int inv(int x) 
    {
        return fast_pow(x, mod - 2);
    }

    int C(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        if (n <= max_n) return (((fact[n] * ifact[m]) % mod) * ifact[n - m]) % mod;

        int res = ifact[m];
        for (int i = 1; i <= m; i++) res = (res * ((n - m + i))) % mod;

        return res;
    }

    int A(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        if (n <= max_n) return (fact[n] * ifact[n - m]) % mod;
        
        int res = 1;
        for (int i = 1; i <= m; i++) res = (res * (n - m + i)) % mod;
        return res;
    }
} comb;

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