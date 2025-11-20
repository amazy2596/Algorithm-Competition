#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
const i64 mod = 1e9 + 7;

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
// snippet-end

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