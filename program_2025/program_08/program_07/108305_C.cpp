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
    int n, H;
    cin >> n >> H;
    vector<pair<i64, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        i64 h;
        cin >> h;
        a[i].second = i + 1;
        if (h > H)
            continue;
        a[i].first = (H - h) * h;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        cout << a[i].second << " \n"[i == n - 1];
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