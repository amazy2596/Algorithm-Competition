#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

const i64 mod = 998244353;
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
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    auto dfs = [&](auto dfs, i64 a, i64 b, i64 c, i64 d) -> i64
    {
        if (b > d)
        {
            swap(a, c);
            swap(b, d);
        }

        i64 g = gcd(a, c);
        if (g == 1) return 1LL;

        return (fast_pow(g, b) * dfs(dfs, a / g, b, g, d - b)) % mod;
    };

    cout << dfs(dfs, a, b, c, d) % mod << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}