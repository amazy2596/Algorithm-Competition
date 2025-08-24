#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 998244353;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;
    vector<int> phi;
    vector<int> mu;
    vector<int> tau, cnt;

    LinearSieve(int _n = 2e6 + 5, bool enable_phi = false, bool enable_mu = false, bool enable_tau = false) : n(_n)
    {
        minp.resize(n + 1);
        if (enable_phi) 
        {
            phi.resize(n + 1);
            phi[1] = 1;
        }
        if (enable_mu) 
        {
            mu.resize(n + 1);
            mu[1] = 1;
        }
        if (enable_tau) 
        { 
            tau.resize(n + 1);
            cnt.resize(n + 1); 
            tau[1] = 1;
        }
        
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                primes.push_back(i);

                if (enable_phi) phi[i] = i - 1;
                if (enable_mu) mu[i] = -1;
                if (enable_tau) { tau[i] = 2, cnt[i] = 1; }
            }
            for (int p : primes) 
            {
                i64 x = 1LL * i * p;
                if (x > n) break;
                minp[x] = p;
                
                if (p == minp[i])
                {
                    if (enable_phi) phi[x] = 1LL * p * phi[i];
                    if (enable_mu) mu[x] = 0;
                    if (enable_tau) 
                    {
                        cnt[x] = cnt[i] + 1;
                        tau[x] = tau[i] / (cnt[i] + 1) * (cnt[x] + 1);
                    }
                    break;
                }
                else 
                {
                    if (enable_phi) phi[x] = 1LL * (p - 1) * phi[i];
                    if (enable_mu) mu[x] = -mu[i];
                    if (enable_tau)
                    {
                        cnt[x] = 1;
                        tau[x] = tau[i] * 2;
                    }
                }
            }
        }
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
} LS(2e6 + 5, false, true, true);

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

    vector<int> f(n + 1);
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 2] + f[i - 1];

    vector<i64> h(n + 1);
    for (int d = 1; d <= n; d++)
    {
        for (int m = 1; m * d <= n; m++)
        {
            int x = d * m;
            h[x] = (h[x] + 1LL * LS.tau[d] * f[d] * LS.mu[m]) % mod;
        }
    }

    i64 ans = 0;
    for (int x = 1; x <= n; x++)
        ans = (ans + fast_pow(n / x, 3) * h[x]) % mod;

    cout << ans << "\n";
}

int main()
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