#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];

    vector<array<int, 3>> seg;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            seg.push_back({pre[j] - pre[i - 1], i, j});

    sort(seg.begin(), seg.end());

    int ans = 1e18l;
    for (int i = 1; i < seg.size(); i++)
    {
        auto [s1, l1, r1] = seg[i - 1];
        auto [s2, l2, r2] = seg[i];

        if (r1 < l2 || r2 < l1)
            ans = min(ans, abs(s1 - s2));
    }

    cout << ans << "\n";
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