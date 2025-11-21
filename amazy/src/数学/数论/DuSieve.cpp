#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t; // 防止中间计算溢出

using u64 = uint64_t;
struct safe_hash {
    static u64 splitmix64(u64 x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(u64 x) const {
        static const u64 seed = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + seed);
    }
};
/*
    杜教筛模板，预处理时间 O(N log log N)，查询时间 O(N^(2/3))
    支持莫比乌斯函数 μ(n) 和 欧拉函数 φ(n) 的前缀和查询
*/
struct DuSieve {
    static const int MAXN = 5000005; // 预处理阈值，通常设为 N^(2/3) 或 5e6
    vector<int> primes;
    vector<bool> is_prime;
    vector<i64> sum_mu;  // mu 的前缀和
    vector<i64> sum_phi; // phi 的前缀和
    unordered_map<i64, i64, safe_hash> map_mu;
    unordered_map<i64, i64, safe_hash> map_phi;

    DuSieve() { init(); }
    void init() {
        is_prime.assign(MAXN, true);
        is_prime[0] = is_prime[1] = false;
        sum_mu.resize(MAXN);
        sum_phi.resize(MAXN);
        
        sum_mu[1] = 1;
        sum_phi[1] = 1;

        for (int i = 2; i < MAXN; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                sum_mu[i] = -1;
                sum_phi[i] = i - 1;
            }
            for (int p : primes) {
                if (i * p >= MAXN) break;
                is_prime[i * p] = false;
                if (i % p == 0) {
                    sum_mu[i * p] = 0;
                    sum_phi[i * p] = sum_phi[i] * p;
                    break;
                } else {
                    sum_mu[i * p] = -sum_mu[i];
                    sum_phi[i * p] = sum_phi[i] * (p - 1);
                }
            }
        }
        for (int i = 1; i < MAXN; ++i) {
            sum_mu[i] += sum_mu[i - 1];
            sum_phi[i] += sum_phi[i - 1];
        }
    }

    i64 get_sum_mu(i64 n) {
        if (n < MAXN) return sum_mu[n];
        if (map_mu.count(n)) return map_mu[n];
        i64 ans = 1;
        for (i64 l = 2, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans -= (r - l + 1) * get_sum_mu(n / l);
        }
        return map_mu[n] = ans;
    }

    i64 get_sum_phi(i64 n) {
        if (n < MAXN) return sum_phi[n];
        if (map_phi.count(n)) return map_phi[n];
        i128 total = (i128)n * (n + 1) / 2;
        i64 ans = (i64)total;

        for (i64 l = 2, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans -= (r - l + 1) * get_sum_phi(n / l);
        }
        return map_phi[n] = ans;
    }
} ds;