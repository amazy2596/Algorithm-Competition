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



void solve()
{
    int id, m = 100, k = 10, n = 10;
    cin >> id >> m >> k >> n;
    string s;
    int cnt_0 = rnd(1, 100), cnt_1 = m - cnt_0;
    while (s.length() < m)
    {
        int x = rnd(0, 1);
        if (x == 0 && cnt_0)
            cnt_0--, s += '0';
        else if (x == 1 && cnt_1)
            cnt_1--, s += '1';
    }

    cout << s << "\n";
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