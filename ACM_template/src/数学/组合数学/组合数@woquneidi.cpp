vector<i64> fac, invfac;
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}
 
void init(int n) {
    fac.resize(n + 1);
    invfac.resize(n + 1);
 
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    invfac[n] = power(fac[n], mod - 2);  // 使用费马小定理求逆元
    for (int i = n - 1; i >= 0; i--) {
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
    }
}
 
// 计算组合数 C(n, m)
int binom(int n, int m) {
    if (n < m || m < 0) return 0;
    return 1LL * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
int A(int n, int m) {
	return 1ll * fac[n] * invfac[n - m] % mod;
}
