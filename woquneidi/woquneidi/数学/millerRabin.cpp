//O(klog^3(n)), k = 7
#include <bits/stdc++.h>
using i64 = long long;

i64 qmi(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    while(b) {
        if(b & 1) {
            res = (__int128)res * a % mod;
        }
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

bool Minller(i64 n) {
    if(n <= 1 || n % 2 == 0) return (n == 2);
    i64 u = n - 1, k = 0;
    while(u % 2 == 0) u /= 2, ++k;
    static std::vector<i64> base = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for(auto x : base) {
        i64 res = qmi(x, u, n);
        if(res == 0 || res == 1 || res == n - 1) continue;
        for(int i = 1; i <= k; ++i) {
            res = (__int128)res * res % n;
            if(res == n - 1) break;
            if(i == k) return false;
        }
    }
    return true;
}

void solve() {
    i64 x;
    std::cin >> x;
    std::cout << (Minller(x) ? "YES" : "NO") << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}