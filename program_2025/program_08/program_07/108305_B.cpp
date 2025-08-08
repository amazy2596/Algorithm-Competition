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

constexpr int rev = (1LL << 30) - 1;

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    string ans = "";
    int cur = 0;

    vector<i64> f(4);
    f[0] = a & rev, f[1] = b & rev, f[2] = c & rev;
    int j = 3;

    for (int i = 0; i < n; i++)
    {
        while (j - 3 <= i)
        {
            i64 g = f[0] ^ (((1LL << 16) * f[0]) & rev);
            i64 h = g ^ (g / (1LL << 5));
            f[3] = h ^ ((2 * h) & rev) ^ f[1] ^ f[2];
            // cout << f[3] << " ";
            for (int k = 0; k < 3; k++)
                f[k] = f[k + 1];
            j++;
        }

        int k = i + (f[2] % (n - i));
        cur = (cur + (i != k)) % 2;
    }

    ans += (char)(cur + '0');

    for (int i = 1; i < n; i++)
    {
        int tar = n + 3 * i - 1;
        while (j - 3 <= tar)
        {
            i64 g = f[0] ^ (((1LL << 16) * f[0]) & rev);
            i64 h = g ^ (g / (1LL << 5));
            f[3] = h ^ ((2 * h) & rev) ^ f[1] ^ f[2];
            // cout << f[3] << " ";
            for (int k = 0; k < 3; k++)
                f[k] = f[k + 1];
            j++;
        }

        i64 l = min(f[0] % n, f[1] % n);
        i64 r = max(f[0] % n, f[1] % n);
        i64 d = f[2] % n + 1;
        // cout << "query" << i << ": " << l << " " << r << " " << d << "\n";

        cur = (cur + d * (r - l)) % 2;
        ans += (char)(cur + '0');
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
