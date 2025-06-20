#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int k;
    cin >> k;

    // 3 5 9 15 21 25 27 33 35 39 45 51 55 57 63 65 69 75 81 85 87 93 95 99 
    auto check = [&](int x) -> int
    {
        if (x >= 3 && x < 5)
            return 1;
        if (x >= 5 && x < 15)
            return 2 + (x >= 9);

        return ((x - 3) / 6 + 1 + (x - 5) / 10 - (x - 15) / 30);
    };
    int l = 3, r = 1e12l;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid) >= k)
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << "\n";
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