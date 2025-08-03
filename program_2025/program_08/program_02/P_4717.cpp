#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

const int mod = 998244353;
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

struct FWT
{
    FWT() {}

    static void OR(vector<i64> &a, int type)
    {
        int n = a.size();
        for (int len = 2; len <= n; len <<= 1)
        {
            int step = len / 2;
            for (int i = 0; i < n; i += len)
            {
                for (int j = 0; j < step; j++)
                {
                    a[i + j + step] = (a[i + j + step] + type * a[i + j] + mod) % mod;
                }
            }
        }
    }

    static void AND(vector<i64> &a, int type)
    {
        int n = a.size();
        for (int len = 2; len <= n; len <<= 1)
        {
            int step = len / 2;
            for (int i = 0; i < n; i += len)
            {
                for (int j = step - 1; j >= 0; j--)
                {
                    a[i + j] = (a[i + j] + type * a[i + j + step] + mod) % mod;
                }
            }
        }
    }

    static void XOR(vector<i64> &a, int type)
    {
        int n = a.size();
        for (int len = 2; len <= n; len <<= 1)
        {
            int step = len / 2;
            for (int i = 0; i < n; i += len)
            {
                for (int j = 0; j < step; j++)
                {
                    i64 u = a[i + j];
                    i64 v = a[i + j + step];

                    a[i + j] = (u + v) % mod;
                    a[i + j + step] = ((u - v) % mod + mod) % mod;
                }
            }
        }

        if (type == -1)
        {
            i64 invN = inv(n);
            for (auto &x : a) 
            {
                x = (x * invN) % mod;
            }
        }
    }

    using Func = function<void(vector<i64>&, int)>;
    vector<i64> work(const vector<i64> &a, const vector<i64> &b, Func op)
    {
        int tot = max(a.size(), b.size());
        if (tot <= 0) return {};
        int n = 1;
        while (n < tot) n <<= 1;

        vector<i64> fa(a);
        vector<i64> fb(b);

        fa.resize(n);
        fb.resize(n);

        op(fa, 1);
        op(fb, 1);

        for (int i = 0; i < n; i++)
            fa[i] = (fa[i] * fb[i]) % mod;

        op(fa, -1);
        fa.resize(tot);
        return fa;
    }
} fwt;

void solve()
{
    i64 n;
    cin >> n;
    n = (1LL << n);
    vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    auto ans1 = fwt.work(a, b, FWT::OR);
    for (auto x : ans1) cout << x << " \n"[x == ans1.back()];
    auto ans2 = fwt.work(a, b, FWT::AND);
    for (auto x : ans2) cout << x << " \n"[x == ans2.back()];
    auto ans3 = fwt.work(a, b, FWT::XOR);
    for (auto x : ans3) cout << x << " \n"[x == ans3.back()];
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}