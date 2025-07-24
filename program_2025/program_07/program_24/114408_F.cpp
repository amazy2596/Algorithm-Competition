#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

const double eps = 1e-12;
// const int inf = 1e18;

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

    Comb(int n) : max_n(0)
    {
        fact.push_back(1);
        ifact.push_back(1);
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

struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;
    vector<int> phi;
    vector<int> mu;

    LinearSieve(int n = 2e6 + 5, bool enable_phi = false, bool enable_mu = false)
    {
        minp.resize(n + 1);
        if (enable_phi) phi.resize(n + 1);
        if (enable_mu) mu.resize(n + 1);
        
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                primes.push_back(i);

                if (enable_phi) phi[i] = i - 1;
                if (enable_mu) mu[i] = -1;
            }
            for (int p : primes) 
            {
                if (1LL * i * p >= n || p > minp[i])
                    break;

                minp[i * p] = p;
                
                if (p == minp[i])
                {
                    if (enable_phi) phi[i * p] = 1LL * p * phi[i];
                    if (enable_mu) mu[i * p] = 0;
                    break;
                }
                else 
                {
                    if (enable_phi) phi[i * p] = 1LL * (p - 1) * phi[i];
                    if (enable_mu) mu[i * p] = -mu[i];
                }
            }
        }

        if (enable_phi) phi[1] = 1;
        if (enable_mu) mu[1] = 1;
    }

    vector<pair<int, int>> factorize(int x) 
    {
        vector<pair<int, int>> facts;

        if (x <= n)
        {
            while (x > 1)
            {
                int p = minp[x];
                int count = 0;
                while (x % p == 0)
                {
                    x /= p;
                    count++;
                }
                facts.push_back({p, count});
            }

            return facts;
        }

        for (int p : primes) 
        {
            if (1LL * p * p > x) break;

            if (x % p == 0) 
            {
                int count = 0;
                while (x % p == 0) 
                {
                    x /= p;
                    count++;
                }
                facts.push_back({p, count});
            }
        }

        if (x > 1) facts.push_back({x, 1});

        return facts;
    }

    bool is_prime(int x) 
    {
        if (x < 2 || x > n) return false;
        return minp[x] == x;
    }
} LS(2e7 + 5, false, true);

void solve()
{
    int n, m;
    cin >> n >> m;

    if (m == 1)
    {
        cout << n - 1 << "\n";
        return;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // ans = (ans + 1ll * LS.mu[i] * Comb.C(n / i, m) + mod) % mod;
        long long tmp = (LS.mu[i] + mod) % mod;
        tmp = (tmp * Comb.C(n / i, m)) % mod;
        ans = (ans + tmp) % mod;
    }

    cout << ((Comb.C(n, m) - ans) % mod + mod) % mod << "\n";
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