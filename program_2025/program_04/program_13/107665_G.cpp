#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;

    auto get = [&](int n)
    {
        return n / 4 - n / 100 + n / 400;
    };

    auto calc = [&](int l, int r)
    {
        return get(r) - get(l - 1);
    };

    cout << calc(x, y) << "\n";
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