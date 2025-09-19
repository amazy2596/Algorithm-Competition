// Problem: 【模板】子集卷积
// URL: https://www.luogu.com.cn/problem/P6097
// Author: amazy
// Date: 2025-09-19 17:35:00

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 9;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    int tot = 1LL << n;
    vector<i64> a(tot), b(tot);
    for (int i = 0; i < tot; i++) cin >> a[i];
    for (int i = 0; i < tot; i++) cin >> b[i];

    vector<int> pc(tot);
    for (int i = 0; i < tot; i++)
        pc[i] = pc[i >> 1] + (i & 1);

    vector<vector<i64>> F(n + 1, vector<i64>(tot)), G(n + 1, vector<i64>(tot));
    for (int mask = 0; mask < tot; mask++)
    {
        F[pc[mask]][mask] = a[mask];
        G[pc[mask]][mask] = b[mask];
    }

    auto sos_zeta = [&](vector<vector<i64>> &T)
    {
        for (int p = 0; p <= n; p++)
        {
            for (int bit = 0; bit < n; bit++)
            {
                for (int mask = 0; mask < tot; mask++)
                {
                    if (mask & (1LL << bit)) 
                        T[p][mask] += T[p][mask ^ (1LL << bit)];
                    T[p][mask] %= mod;
                }
            }
        }
    };

    auto sos_izeta = [&](vector<vector<i64>> &T)
    {
        for (int p = 0; p <= n; p++)
        {
            for (int bit = 0; bit < n; bit++)
            {
                for (int mask = 0; mask < tot; mask++)
                {
                    if (mask & (1LL << bit)) 
                        T[p][mask] -= T[p][mask ^ (1LL << bit)];
                    T[p][mask] %= mod;
                }
            }
        }
    };

    sos_zeta(F);
    sos_zeta(G);

    vector<vector<i64>> H(n + 1, vector<i64>(tot, 0));
    for (int mask = 0; mask < tot; mask++)
    {
        for (int p = 0; p <= n; p++)
        {
            i128 sum = 0;
            for (int q = 0; q <= p; q++)
                sum = (sum + F[q][mask] * G[p - q][mask]) % mod;
            H[p][mask] = sum % mod;
        }
    }

    sos_izeta(H);

    for (int mask = 0; mask < tot; mask++)
    {
        H[pc[mask]][mask] %= mod;
        H[pc[mask]][mask] += mod;
        H[pc[mask]][mask] %= mod;
        cout << H[pc[mask]][mask] << " ";
    }
}

int main()
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