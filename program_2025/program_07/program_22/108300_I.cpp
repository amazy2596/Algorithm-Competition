#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MOD = 998244353;
const int NTT_PRIMITIVE_ROOT = 3;
// 增加 MAXN 以处理最大查询 n=2e5
const int MAXN_Q = 200001;
const int MAXN_NTT = 1 << 19; // 2^18 = 262144, 2^19 = 524288，取一个足够大的2的幂

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void ntt(vector<long long>& a, bool invert) {
    int n = a.size();
    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = power(NTT_PRIMITIVE_ROOT, (MOD - 1) / len);
        if (invert)
            wlen = modInverse(wlen);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long long u = a[i + j], v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = (w * wlen) % MOD;
            }
        }
    }

    if (invert) {
        long long n_inv = modInverse(n);
        for (long long& x : a)
            x = (x * n_inv) % MOD;
    }
}

vector<long long> multiply(vector<long long> a, vector<long long> b) {
    int res_deg = a.size() + b.size() - 2;
    int sz = 1;
    while (sz < a.size() + b.size()) sz <<= 1;
    a.resize(sz);
    b.resize(sz);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < sz; i++) a[i] = (a[i] * b[i]) % MOD;
    ntt(a, true);
    a.resize(res_deg + 1);
    return a;
}

vector<long long> poly_inverse(const vector<long long>& a, int n) {
    if (n == 1) return {modInverse(a[0])};
    vector<long long> a0 = poly_inverse(a, (n + 1) / 2);
    vector<long long> sub_a(a.begin(), a.begin() + min((int)a.size(), n));
    int sz = 1;
    while (sz < 2 * n) sz <<= 1;
    a0.resize(sz);
    sub_a.resize(sz);
    ntt(a0, false);
    ntt(sub_a, false);
    for (int i = 0; i < sz; i++) {
        long long term = (2 - (sub_a[i] * a0[i]) % MOD + MOD) % MOD;
        a0[i] = (a0[i] * term) % MOD;
    }
    ntt(a0, true);
    a0.resize(n);
    return a0;
}

vector<long long> poly_derivative(const vector<long long>& a) {
    if (a.empty()) return {};
    vector<long long> res(a.size() - 1);
    for (size_t i = 1; i < a.size(); ++i) {
        res[i - 1] = (a[i] * i) % MOD;
    }
    return res;
}

vector<long long> poly_integral(const vector<long long>& a) {
    vector<long long> res(a.size() + 1, 0);
    vector<long long> inv(a.size() + 1);
    inv[1] = 1;
    for(size_t i = 2; i <= a.size(); ++i) inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;

    for (size_t i = 0; i < a.size(); ++i) {
        res[i + 1] = (a[i] * inv[i + 1]) % MOD;
    }
    return res;
}

// *** BUG FIX HERE ***
// Changed signature to pass 'a' by value, and added a.resize(n).
vector<long long> poly_log(vector<long long> a, int n) {
    a.resize(n);
    vector<long long> deriv_a = poly_derivative(a);
    vector<long long> inv_a = poly_inverse(a, n);
    vector<long long> res = multiply(deriv_a, inv_a);
    res.resize(n - 1);
    return poly_integral(res);
}

vector<long long> poly_exp(const vector<long long>& a, int n) {
    if (n == 1) return {1};
    vector<long long> b = poly_exp(a, (n + 1) / 2);
    vector<long long> log_b = poly_log(b, n); // This call is now safe
    
    vector<long long> sub_a(n, 0);
    for(size_t i = 0; i < a.size() && i < n; ++i) {
        sub_a[i] = a[i];
    }
    
    vector<long long> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = (sub_a[i] - log_b[i] + MOD) % MOD;
    }
    res[0] = (res[0] + 1) % MOD;
    
    res = multiply(b, res);
    res.resize(n);
    return res;
}

long long fact[MAXN_NTT], invFact[MAXN_NTT];

void precompute_factorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[n] = modInverse(fact[n]);
    for (int i = n - 1; i >= 0; --i) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long k;
    cin >> t >> k;

    int max_n = 0;
    vector<int> queries(t);
    for (int i = 0; i < t; ++i) {
        cin >> queries[i];
        if (queries[i] > max_n) {
            max_n = queries[i];
        }
    }
    
    int N = 1;
    while(N <= max_n) N <<= 1;

    precompute_factorials(N);

    long long K = k + 1;
    long long K_mod_phi = K % (MOD - 1);
    if (K_mod_phi == 0) K_mod_phi = MOD - 1;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = power(invFact[i], K_mod_phi);
    }
    
    vector<long long> B(N);
    for (int i = 1; i < N; ++i) {
        B[i] = (i * A[i]) % MOD;
    }
    
    vector<long long> r = multiply(B, poly_inverse(A, N));
    r.resize(N);

    vector<long long> c(N, 0);
    long long k_mod_phi = k % (MOD - 1);
    if(k_mod_phi == 0 && k > 0) k_mod_phi = MOD - 1;

    for (int j = 1; j < N; ++j) {
        long long j_inv = modInverse(j);
        long long j_pow_neg_k = power(j_inv, k_mod_phi);
        long long j_pow_neg_K = power(j_inv, K_mod_phi);
        
        for (int m = 1; m * j < N; ++m) {
            if (r[m] == 0) continue;
            int i = m * j;
            long long term = (r[m] * j_pow_neg_k) % MOD;
            c[i] = (c[i] + term) % MOD;
            j_pow_neg_k = (j_pow_neg_k * j_pow_neg_K) % MOD;
        }
    }
    
    vector<long long> D(N, 0);
    vector<long long> inv_n(N+1);
    inv_n[1] = 1;
    for(int i = 2; i < N; ++i) inv_n[i] = MOD - (MOD/i) * inv_n[MOD%i] % MOD;

    for(int i = 1; i < N; ++i) {
        D[i] = (c[i] * inv_n[i]) % MOD;
    }
    
    vector<long long> g = poly_exp(D, N);
    
    vector<long long> n_fact_K(N);
    n_fact_K[0] = 1;
    for(int i = 1; i < N; ++i) {
        n_fact_K[i] = power(fact[i], K_mod_phi);
    }
    
    vector<long long> ans(N);
    for(int i=0; i<N; ++i) {
        ans[i] = (g[i] * n_fact_K[i]) % MOD;
    }
    
    for(int n_query : queries) {
        cout << ans[n_query] << "\n";
    }

    return 0;
}