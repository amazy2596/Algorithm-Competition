#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

i64 fast_pow(i64 a, i64 b, i64 p) {
    i64 res = 1;
    while (b) {
        if (b & 1) {
            res = (i128)res * a % p;
        }
        a = (i128)a * a % p;
        b >>= 1;
    }
    return res;
}

bool is_prime(i64 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    i64 u = n - 1;
    int t = 0;
    while (u % 2 == 0) { u /= 2; t++; }

    static const vector<i64> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (i64 a : bases) {
        if (a % n == 0) continue;
        i64 v = fast_pow(a, u, n);
        if (v == 1 || v == n - 1) continue;

        bool passed = false;
        for (int i = 1; i < t; ++i) {
            v = (i128)v * v % n;
            if (v == n - 1) {
                passed = true;
                break;
            }
            if (v == 1) return false;
        }
        if (!passed) return false;
    }
    
    return true;
}

// 寻找 n 的一个非平凡因子 (不一定是素数)
i64 pollard_rho(i64 n) {
    if (n == 4) return 2;
    if (n % 2 == 0) return 2;
    
    i64 c = rnd(1, n - 1); 
    auto f = [&](i64 x) { return ((i128)x * x + c) % n; };
    
    i64 x = rnd(1, n - 1);
    i64 y = x;
    i64 val = 1;
    
    for (int step = 1; ; step <<= 1) {
        i64 check_point = x;
        
        for (int i = 0; i < step; i++) {
            x = f(x);
            i64 diff = x > y ? x - y : y - x;
            val = (i128)val * diff % n;
            
            if ((i + 1) % 127 == 0) {
                i64 d = gcd(val, n);
                if (d > 1) return d;
            }
        }
        
        i64 d = gcd(val, n);
        if (d > 1) return d;
        
        y = x;
        val = 1;
    }
    return n;
}

// n的范围是[1, 1e18]
void factorize(i64 n, vector<i64>& factors) {
    if (n == 1) return;
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    
    i64 factor = n;
    while (factor >= n) factor = pollard_rho(n);
    
    factorize(factor, factors);
    factorize(n / factor, factors);
}
// snippet-end