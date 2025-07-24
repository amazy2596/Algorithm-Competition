#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

const double eps = 1e-12;
const long long inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int N = 4e7 + 5;
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

    LinearSieve(int n = 2e6 + 5)
    {
        minp.resize(n + 1);
        phi.resize(n + 1);
        mu.resize(n + 1);
        
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                phi[i] = i - 1;
                mu[i] = -1;
                primes.push_back(i);
            }
            for (int p : primes) 
            {
                if (1LL * i * p >= n || p > minp[i])
                    break;

                minp[i * p] = p;
                
                if (p == minp[i])
                {
                    phi[i * p] = (1LL * p * phi[i]) % mod;
                    mu[i * p] = 0;
                    break;
                }
                else 
                {
                    phi[i * p] = (1LL * (p - 1) * phi[i]) % mod;
                    mu[i * p] = -mu[i];
                }
            }
        }

        phi[1] = 1;
        mu[1] = 1;
    }

    map<int, int> factorize(int x) 
    {
        map<int, int> facts;

        if (x <= n)
        {
            while (x > 1)
            {
                facts[minp[x]]++;
                x /= minp[x];
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
                facts[p] = count;
            }
        }

        if (x > 1) facts[x] = 1;

        return facts;
    }

    bool is_prime(int x) 
    {
        if (x < 2 || x > n) return false;
        return minp[x] == x;
    }
} LS(N);

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = (pre[i - 1] + LS.mu[i] + mod) % mod;

    int ans = 0;
    int l = 1;
    while (l <= n)
    {
        int v = n / l;
        int r = n / v;

        ans = (ans + 1ll * Comb.C(v, m) * (pre[r] - pre[l - 1] + mod) % mod) % mod;
        l = r + 1;
    }

    ans = (Comb.C(n, m) - ans + mod) % mod;
    cout << ans << "\n";
}

signed main()
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