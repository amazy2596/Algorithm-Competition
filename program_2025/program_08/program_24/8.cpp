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

template<i64 mod>
struct NTT 
{
    int G = 3;
    vector<int> rev;            
    vector<i64> roots = {0, 1}; 

    i64 fast_pow(i64 a, i64 b) 
    {
        i64 res = 1;
        a %= mod;
        while (b) 
        {
            if (b & 1)
                res = ((i128)res * a) % mod;

            a = ((i128)a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    i64 inv(i64 x) 
    {
        return fast_pow(x, mod - 2);
    }

    /**
     * @brief 计算模意义下的二次剩余，即求解方程 x^2 = a (mod p)。
     *        该函数实现了 Tonelli-Shanks 算法，并包含了针对特殊情况的优化。
     * 
     * @param a 方程中的常数项 a。
     * @param mod 模数 p，要求必须是一个奇素数。
     * @return  如果方程有解，返回其中一个解 x。方程的另一个解是 mod - x。
     *          如果方程无解，返回 -1。
     *          如果 a = 0，返回 0。
     */
    i64 sqrt_mod(i64 a) 
    {
        // 将 a 化为最小正整数
        a %= mod;
        if (a < 0) a += mod;

        // ----- 特殊情况处理 -----
        // a = 0，解为 0
        if (a == 0) return 0;
        // p = 2，解为 a 本身
        if (mod == 2) return a;

        // ----- 使用欧拉判别法检查解是否存在 -----
        // (a/p) = a^((p-1)/2) mod p
        // 如果结果为 p-1 (即 -1)，则无解
        if (fast_pow(a, (mod - 1) / 2) == mod - 1)
            return -1;

        // ----- p = 3 (mod 4) 的简单情况 -----
        // x = a^((p+1)/4) mod p
        if (mod % 4 == 3)
            return fast_pow(a, (mod + 1) / 4);

        // ----- p = 1 (mod 4) 的 Tonelli-Shanks 算法 -----
        // 1. 将 p-1 分解为 Q * 2^S，其中 Q 是奇数
        i64 S = 0;
        i64 Q = mod - 1;
        while (Q % 2 == 0)
        {
            S++;
            Q /= 2;
        }
        // 如果 S=1, 那么 p = Q*2+1, Q为奇数, p=2Q+1, 此时 p%4=3，上面已处理
        // 所以这里的 S >= 2

        // 2. 找到一个二次非剩余 n
        i64 n = 2;
        while (fast_pow(n, (mod - 1) / 2) != mod - 1) 
            n++;

        // 3. 初始化变量
        i64 M = S;
        i64 c = fast_pow(n, Q); // c = n^Q mod p
        i64 t = fast_pow(a, Q); // t = a^Q mod p
        i64 R = fast_pow(a, (Q + 1) / 2); // R = a^((Q+1)/2) mod p

        // 4. 主循环
        while (t != 1) 
        {
            if (t == 0) return 0; // a 是 0 的情况
            
            // 找到最小的 i > 0 使得 t^(2^i) = 1 (mod p)
            i64 i = 0;
            i64 temp_t = t;
            while (temp_t != 1) 
            {
                temp_t = (i128)temp_t * temp_t % mod;
                i++;
            }
            
            // 理论上不会发生，除非输入p不是素数
            if (i >= M) return -1;

            // 计算 b = c^(2^(M-i-1))
            i64 b_exp = 1LL << (M - i - 1); // 2^(M-i-1)
            i64 b = fast_pow(c, b_exp);

            // 更新 M, c, t, R
            M = i;
            c = (i128)b * b % mod;
            t = (i128)t * c % mod;
            R = (i128)R * b % mod;
        }

        return R;
    }

    /**
     * @brief 执行正向NTT (DFT)，这是一个原地变换。
     * @param a 多项式系数向量。
     */
    void dft(vector<i64> &a) 
    {
        int n = a.size();
        if (rev.size() != n) 
        {
            int k = __builtin_ctz(n) - 1;
            rev.resize(n);
            for (int i = 0; i < n; i++)
                rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
        for (int i = 0; i < n; i++) 
            if (rev[i] < i) 
                swap(a[i], a[rev[i]]);

        if (roots.size() < n) 
        {
            int k = __builtin_ctz(roots.size());
            roots.resize(n);
            while ((1 << k) < n) 
            {
                i64 e = fast_pow(G, (mod - 1) / (1LL << (k + 1)));
                for (int i = 1 << (k - 1); i < (1 << k); i++) 
                {
                    roots[2 * i] = roots[i];
                    roots[2 * i + 1] = (roots[i] * e) % mod;
                }
                k++;
            }
        }

        for (int len = 2; len <= n; len <<= 1) 
        {
            for (int i = 0; i < n; i += len) 
            {
                for (int j = 0; j < len / 2; j++) 
                {
                    i64 u = a[i + j];
                    i64 v = (roots[j + len / 2] * a[i + j + len / 2]) % mod;
                    a[i + j] = (u + v) % mod;
                    a[i + j + len / 2] = (u - v + mod) % mod;
                }
            }
        }
    }

    /**
     * @brief 执行逆向NTT (IDFT)，这是一个原地变换。
     * @param a 经过DFT的点值表示向量。
     */
    void idft(vector<i64> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        i64 tmp = inv(n);
        for (int i = 0; i < n; i++)
            a[i] = (a[i] * tmp) % mod;
    }

    /**
     * @brief 使用NTT计算两个多项式的乘积（卷积）。
     * @param a 第一个多项式的系数。
     * @param b 第二个多项式的系数。
     * @return 结果多项式的系数。
     */
    vector<i64> mul(const vector<i64> &a, const vector<i64> &b) 
    {
        int tot = a.size() + b.size() - 1;
        if (tot <= 0) return {};

        if (tot <= 128) 
        {
            vector<i64> c(tot);
            for (int i = 0; i < a.size(); i++)
            {
                for (int j = 0; j < b.size(); j++)
                {
                    c[i + j] = (c[i + j] + (i128)a[i] * b[j]) % mod;
                }
            }
            return c;
        }

        int n = 1;
        while (n < tot) n <<= 1;

        vector<i64> fa(a); 
        vector<i64> fb(b);
        
        fa.resize(n);
        fb.resize(n);

        dft(fa);
        dft(fb);

        for (int i = 0; i < n; i++)
            fa[i] = (fa[i] * fb[i]) % mod;

        idft(fa);
        fa.resize(tot);
        return fa;
    }

    /**
     * @brief 使用牛顿迭代法，计算多项式 A(x) 的模 x^n 乘法逆元。
     *        寻找一个多项式 B(x)，使得 A(x) * B(x) = 1 (mod x^n)。
     *        此版本在频域（点值表示）中进行核心计算，以减少 NTT/INTT 调用次数。
     *        迭代公式为 B_new = B_old * (2 - A * B_old)。
     * 
     * @param a 输入多项式 A(x) 的系数向量。
     * @param n 结果所需的精度，即返回的多项式的系数数量。
     * @return  一个系数向量，表示逆元多项式 B(x) 的前 n 项系数。
     */
    vector<i64> inv_poly(const vector<i64> &a, int n)
    {
        assert(a.size() > 0 && a[0] != 0);

        vector<i64> b = {inv(a[0], mod)};

        int k = 1;
        while (k < n)
        {
            int nk = k << 1;
            
            int limit = 1;
            while (limit < (nk << 1)) limit <<= 1;

            vector<i64> tmp_a(a.begin(), a.begin() + min(nk, (int)a.size()));
            tmp_a.resize(limit);
            b.resize(limit);
            
            dft(tmp_a);
            dft(b);

            for (int i = 0; i < limit; i++)
            {
                i64 term = (2 - (tmp_a[i] * b[i]) % mod + mod) % mod;
                b[i] = (b[i] * term) % mod;
            }

            idft(b);

            b.resize(nk);
            k = nk;
        }

        b.resize(n);
        return b;
    }

    /**
     * @brief 计算多项式在模 mod 意义下的平方根。
     *        采用牛顿迭代法，每一步迭代将解的精度（正确的系数项数）加倍。
     *        迭代公式为 B_new = (B_old + A * B_old^-1) / 2。
     * @param a 输入多项式 A(x) 的系数向量。
     * @param n 结果多项式所需的项数（即精度，结果对 x^n 取模）。
     * @return  一个向量，表示 A(x) 的平方根 B(x) 的前 n 项系数。
     *          返回的解满足 B(x)^2 = A(x) (mod x^n)。
     */
    vector<i64> sqrt_poly(const vector<i64> &a, int n)
    {
        if (n == 0) return {};
        
        vector<i64> b(1);
        b[0] = sqrt_mod(a[0], mod);
        b[0] = min(b[0], mod - b[0]);

        assert(b[0] >= 0);

        vector<i64> inv_b(1);
        inv_b[0] = inv(b[0], mod);
        i64 inv2 = inv(2, mod);

        int k = 1;
        while (k < n)
        {
            int nk = k << 1;
            vector<i64> inv_b_k = inv_poly(b, nk);

            vector<i64> tmp_a(a.begin(), a.begin() + min(nk, (int)a.size()));
            auto term = mul(tmp_a, inv_b_k);

            b.resize(nk);
            for (int i = 0; i < nk; i++) 
            {
                b[i] = (b[i] + term[i]) % mod;
                b[i] = (b[i] * inv2) % mod;
            }
            
            k = nk;
        }

        b.resize(n);
        return b;
    }

};

struct Comb 
{
    int max_n;          
    vector<int> fact; 
    vector<int> ifact;

    Comb() : max_n(0)
    {
        fact.push_back(1);
        ifact.push_back(1);
    }

    Comb(int n) : max_n(n)
    {
        extend_to(n);
    }

    void extend_to(int new_max_n)
    {
        if (new_max_n <= max_n) return;

        int old_max_n = max_n;
        max_n = new_max_n;

        fact.resize(max_n + 1);
        ifact.resize(max_n + 1);

        for (int i = old_max_n + 1; i <= max_n; i++)
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        
        ifact[max_n] = fast_pow(fact[max_n], mod - 2);
        for (int i = max_n - 1; i > old_max_n; i--)
            ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % mod;
    }

    int fast_pow(int a, int b) 
    {
        int res = 1;
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

    int inv(int x) 
    {
        if (x > max_n) extend_to(x);
        return fast_pow(x, mod - 2);
    }
    
    int C(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        
        if (n > max_n)
            extend_to(2 * n); 

        return (((1LL * fact[n] * ifact[m]) % mod) * ifact[n - m]) % mod;
    }

    int A(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        
        if (n > max_n)
            extend_to(2 * n);
        
        return (1LL * fact[n] * ifact[n - m]) % mod;
    }
} Comb;

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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; i++)
    {
        cntA += (s[i] == 'A');
        cntB += (s[i] == 'B');
    }

    NTT<mod> ntt;
    vector<i64> a(cntA + 1), b(cntB + 1);
    for (int i = 0; i <= cntA; i++)
        a[i] = (Comb.C(cntA, i) * fast_pow(2, i)) % mod;
    for (int i = 0; i <= cntB; i++)
        b[i] = Comb.C(cntB, i);

    auto res = ntt.mul(a, b);
    i64 ans = 0;
    for (int i = 0; i <= m; i++)
        ans = (ans + res[i]) % mod;

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