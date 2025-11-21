#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;

    // 积性函数数组
    vector<int> phi;    // 欧拉函数
    vector<int> mu;     // 莫比乌斯函数
    vector<int> tau;    // 约数个数
    vector<i64> sig;    // 约数和

    // 辅助数组
    vector<int> cnt;    // 最小质因子的指数 (for tau)
    vector<i64> pe;

    LinearSieve(int _n = 2e6 + 5, bool enable_phi = false, bool enable_mu = false, bool enable_tau = false, bool enable_sig = false) : n(_n)
    {
        minp.resize(n + 1);
        if (enable_phi) { phi.resize(n + 1); phi[1] = 1; }
        if (enable_mu)  { mu.resize(n + 1); mu[1] = 1; }
        if (enable_tau) { tau.resize(n + 1); cnt.resize(n + 1); tau[1] = 1; }
        if (enable_sig) { sig.resize(n + 1); pe.resize(n + 1); sig[1] = 1; }
        
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                primes.push_back(i);

                if (enable_phi) phi[i] = i - 1;
                if (enable_mu)  mu[i] = -1;
                if (enable_tau) { tau[i] = 2; cnt[i] = 1; }
                if (enable_sig) { sig[i] = i + 1; pe[i] = i; } // 质数的约数和为 p+1
            }
            for (int p : primes) 
            {
                i64 x = 1LL * i * p;
                if (x > n) break;
                minp[x] = p;
                
                if (p == minp[i])
                {
                    if (enable_phi) phi[x] = phi[i] * p;
                    if (enable_mu)  mu[x] = 0;
                    if (enable_tau) 
                    {
                        cnt[x] = cnt[i] + 1;
                        tau[x] = tau[i] / (cnt[i] + 1) * (cnt[x] + 1);
                    }
                    if (enable_sig)
                    {
                        pe[x] = pe[i] * p;
                        sig[x] = sig[i / pe[i]] * (sig[pe[i]] + pe[x]);
                    }
                    break;
                }
                else 
                {
                    if (enable_phi) phi[x] = phi[i] * (p - 1);
                    if (enable_mu)  mu[x] = -mu[i];
                    if (enable_tau) { cnt[x] = 1; tau[x] = tau[i] * 2; }
                    if (enable_sig) { pe[x] = p; sig[x] = sig[i] * (p + 1); }
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
} LS(2e6 + 5, false, false, false, false);
