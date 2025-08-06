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

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int mod = mod2;
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
    i64 g = gcd(a, c);
    i64 ans = 1;
    for (int i = 2; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            int cnt = 0;
            int x = a, y = c;
            while (x % i == 0 && y % i == 0)
                x /= i, y /= i;
            ans = (ans * fast_pow(i, min(b, d) * cnt)) % mod;
        }
    }
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