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
} comb(1e5);

struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;
    vector<int> phi;
    vector<int> mu;

    LinearSieve(int n = 2e6 + 5) : n(n), minp(n + 1), phi(n + 1), mu(n + 1)
    {
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
                if (i * p >= n || p > minp[i])
                    break;

                minp[i * p] = p;
                
                if (p == minp[i])
                {
                    phi[i * p] = p * phi[i];
                    mu[i * p] = 0;
                    break;
                }
                else 
                {
                    phi[i * p] = (p - 1) * phi[i];
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
            if (p * p > x) break;

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
} LS(1e5);

void solve()
{
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // dp[0][0] = 1;
    // int op = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     auto ndp = dp;
    //     for (int j = 0; j <= n; j++)
    //     {
    //         int g = gcd(i, j);
    //         if (g == 1)
    //             continue;
    //         for (int k = 1; k <= m; k++)
    //             ndp[g][k] = (ndp[g][k] + dp[j][k - 1]) % mod;
    //     }
    //     dp = move(ndp);
    // }

    // int ans = 0;
    // for (int i = 2; i <= n; i++)
    //     ans = (ans + dp[i][m]) % mod;

    // cout << ans << '\n';

    int ans = 0;
    for (int k = 1; k <= n; k++)
        ans = (ans + LS.mu[k] * comb.C(n / k, m));

    ans = (comb.C(n, m) - ans + mod) % mod;
    cout << ans << "\n";
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