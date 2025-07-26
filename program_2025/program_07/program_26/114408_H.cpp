#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int mod = mod1;
struct Comb 
{
    int max_n;          
    vector<int> fact; 
    vector<int> ifact;

    Comb() : max_n(0)
    {
        fact.push_back(1);
        ifact.push_back(1);
    }

    Comb(int n) : max_n(n)
    {
        extend_to(n);
    }

    void extend_to(int new_max_n)
    {
        if (new_max_n <= max_n) return;

        int old_max_n = max_n;
        max_n = new_max_n;

        fact.resize(max_n + 1);
        ifact.resize(max_n + 1);

        for (int i = old_max_n + 1; i <= max_n; i++)
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        
        ifact[max_n] = fast_pow(fact[max_n], mod - 2);
        for (int i = max_n - 1; i > old_max_n; i--)
            ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % mod;
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

    int inv(int x) 
    {
        if (x > max_n) extend_to(x);
        return fast_pow(x, mod - 2);
    }
    
    int C(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        
        if (n > max_n)
            extend_to(2 * n); 

        return (((1LL * fact[n] * ifact[m]) % mod) * ifact[n - m]) % mod;
    }

    int A(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        
        if (n > max_n)
            extend_to(2 * n);
        
        return (1LL * fact[n] * ifact[n - m]) % mod;
    }
} Comb;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    auto check = [&](int x)
    {
        int res = 0;
        int cnt = 0;
        for (int i = 60; i >= 0; i--)
        {
            if (x >> i & 1)
            {
                res += Comb.C(i, m - cnt);
                cnt++;
            }
        }

        if (cnt == m)
            res++;

        return res >= k;
    };

    int l = 0, r = inf + 5;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << (l > n ? -1 : l) << "\n";
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