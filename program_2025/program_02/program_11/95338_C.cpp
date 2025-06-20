#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << 2 << "\n";
        return;
    }

    auto get = [&](uint x)
    {
        if (x == 1)
            return x;
        int temp = 63 - __builtin_clzll(2 * x);
        return x - (uint)(temp - 1);
    };

    uint l = 1, r = k + 1000;
    while (l < r)
    {
        uint mid = (l + r) >> 1;
        if (get(mid) >= k)
            r = mid;
        else 
            l = mid + 1;
    }

    cout << 2 * l << "\n";
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