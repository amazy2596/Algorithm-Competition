#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> p;
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        p[x[i]] = max(p[x[i]], r[i]);
    }

    map<int, vector<array<int, 2>>> mp;
    for (auto [x, r] : p)
    {
        for (int y = r; y >= -r; y--)
        {
            int dx = sqrt(abs(r * r - y * y));
            mp[y].push_back({x - dx, x + dx});
        }
    }

    int ans = 0;
    for (auto &[y, v] : mp)
    {
        sort(v.begin(), v.end());
        int l = v[0][0], r = v[0][1];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i][0] <= r)
                r = max(r, v[i][1]);
            else
                ans += r - l + 1, l = v[i][0], r = v[i][1];
        }
        ans += r - l + 1;
    }

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