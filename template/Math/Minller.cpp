#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
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
// snippet-end