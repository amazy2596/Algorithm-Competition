#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> line({{1, -1e18l}, {m, m}, {1e18, n}});
    while (q--)
    {
        int a;
        cin >> a;
        bool f = 0;
        for (auto& [l, r] : line)
        {
            if (a < l)
                l = max(1ll, l - 1);
            else if (a > r)
                r = min(n, r + 1);
            else 
            {
                f = 1;
                if (l == r)
                    l = 1e18l, r = -1e18l;
            }
        }
        if (f)
        {
            line[0] = {1, max(line[0].second, 1ll)};
            line[2] = {min(line[2].first, n), n};
        }
        int ans = 0, last_l = 0, last_r = -1;
        for (auto [l, r] : line)
        {
            if (l > r)
                continue;
            if (l > last_r)
            {
                ans += max(0ll, last_r - last_l + 1);
                last_l = l, last_r = r;
            }
            last_r = max(last_r, r);
        }
        ans += max(0ll, last_r - last_l + 1);
        cout << ans << " ";
    }
    cout << "\n";
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