#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int P = 1000000007;
const int P1 = 998244353;
const int P2 = 1004535809;
const int P3 = 469762049;
const int G = 3;

int fast_pow(int a, int b, const int mod) 
{
    int res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (__int128_t)(1LL * res * a) % mod;

        a = (__int128_t)(1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x, int mod) 
{
    return fast_pow(x, mod - 2, mod);
}

struct NTT 
{
    int mod, g;
    vector<int> rev;
    vector<int> roots;

    NTT(int _mod, int _g = 3) : mod(_mod), g(_g) 
    {
        roots = {0, 1};
    }

    void dft(vector<int> &a) 
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
                int e = fast_pow(g, (mod - 1) / (1ll << (k + 1)), mod);
                for (int i = 1 << (k - 1); i < (1 << k); i++) 
                {
                    roots[2 * i] = roots[i];
                    roots[2 * i + 1] = 1LL * roots[i] * e % mod;
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
                    int u = a[i + j];
                    int v = (1LL * roots[j + len / 2] * a[i + j + len / 2]) % mod;
                    a[i + j] = (u + v) % mod;
                    a[i + j + len / 2] = (u - v + mod) % mod;
                }
            }
        }

    }

    void idft(vector<int> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        int tmp = inv(n, mod);
        for (int i = 0; i < n; i++)
            a[i] = (1LL * a[i] * tmp) % mod;
    }

    vector<int> mul(const vector<int> &a, const vector<int> &b) 
    {
        int tot = a.size() + b.size() - 1;
        if (tot <= 0) return {};
        int n = 1;
        while (n < tot) n <<= 1;

        vector<int> fa(a); fa.resize(n);
        vector<int> fb(b); fb.resize(n);

        dft(fa);
        dft(fb);

        for (int i = 0; i < n; i++)
            fa[i] = (1LL * fa[i] * fb[i]) % mod;

        idft(fa);
        fa.resize(tot);
        return fa;
    }
};

NTT ntt1(P1, G), ntt2(P2, G), ntt3(P3, G);
vector<int> mtt(const vector<int> &a, const vector<int> &b)
{
    auto c1 = ntt1.mul(a, b);
    auto c2 = ntt2.mul(a, b);
    auto c3 = ntt3.mul(a, b);

    int n = c1.size();
    vector<int> c(n);

    int inv_p1_p2 = inv(P1, P2);
    int inv_p1p2_p3 = inv((P1 * P2) % P3, P3);

    for (int i = 0; i < n; i++)
    {
        int k1 = (long long)(c2[i] - c1[i] + P2) % P2 * inv_p1_p2 % P2;
        __int128_t c12 = (__int128_t)k1 * P1 + c1[i];
        
        int k2 = (long long)(c3[i] - c12 % P3 + P3) % P3 * inv_p1p2_p3 % P3;
        __int128_t c123 = c12 + (__int128_t)k2 * P1 * P2;
        
        c[i] = c123 % P;
    }

    return c;
}

vector<int> inv_poly(const vector<int> &a, int n)
{
    vector<int> b;
    b.assign(1, inv(a[0], P));

    int k = 1;
    while (k < n)
    {
        int nk = k << 1;
        vector<int> tmp1(a.begin(), a.begin() + min(n, nk));

        auto tmp2 = mtt(tmp1, b);
        tmp2.resize(nk, 0);

        for (int i = 0; i < nk; i++)
            tmp2[i] = (P - tmp2[i]) % P;
        tmp2[0] = (tmp2[0] + 2) % P;

        b = mtt(b, tmp2);
        b.resize(nk, 0);
        k <<= 1;
    }

    b.resize(n, 0);
    return b;
}

void solve()
{
    
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