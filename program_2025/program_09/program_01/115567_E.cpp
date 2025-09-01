// Problem: 中位数+3
// URL: https://ac.nowcoder.com/acm/contest/115567/E
// Author: amazy
// Date: 2025-09-01 17:45:12

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

i64 count_p_in_fact(i64 n, i64 p) 
{
    i64 res = 0;
    while (n) 
    {
        n /= p;
        res += n;
    }
    return res;
}

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

    map<i64, i64> factorize(i64 x) 
    {
        map<i64, i64> facts;

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
                facts[p] += count;
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
                facts[p] += count;
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
} LS(2e6 + 5, false, false, false);

void solve()
{
    i64 n, k;
    cin >> n >> k;

    auto res = LS.factorize(k);
    i64 ans = INF;
    for (auto [p, val] : res)
    {
        i64 tmp = count_p_in_fact(n, p);
        ans = min(ans, tmp / val);
    }

    cout << ans << '\n';
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