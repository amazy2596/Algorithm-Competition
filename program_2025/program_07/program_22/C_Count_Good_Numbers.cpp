#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int l, r;
    cin >> l >> r;

    auto get = [&](int r, int num)
    {
        if (num == 2)
            return r / 2;
        if (num == 3)
            return r / 3 - r / 6;
        if (num == 5)
            return r / 5 - r / 10 - r / 15 + r / 30;
        if (num == 7)
            return r / 7 - r / 14 - r / 21 - r / 35 + r / 42 + r / 70 + r / 105 - r / 210;
    };

    auto query = [&](int l, int r, int num)
    {
        return get(r, num) - get(l - 1, num);
    };

    int ans = r - l + 1;
    ans -= query(l, r, 2);
    ans -= query(l, r, 3);
    ans -= query(l, r, 5);
    ans -= query(l, r, 7);

    cout << ans << "\n";
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