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
    int x, y;
    cin >> x >> y;
    int a, b, c;
    cin >> a >> b >> c;

    i64 p = 1LL * a * inv(a + b) % mod;
    i64 q = 1LL * b * inv(a + b) % mod;

    map<pair<i64, i64>, i64> memo;
    auto dp = [&](auto dp, i64 x, i64 y) -> i64
    {
        if (x == 0) return 0;
        if (y == 0) return 1;
        if (memo.find({x, y}) != memo.end()) return memo[{x, y}];

        i64 res;
        if (x >= y)
        {
            i64 qk = fast_pow(q, x / y);
            res = (1 - qk + qk * dp(dp, x % y, y) + mod) % mod;
        }
        else 
            res = (fast_pow(p, y / x) * dp(dp, x, y % x)) % mod;
        return memo[{x, y}] = res;
    };

    cout << dp(dp, x, y) << "\n";
}

int main()
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