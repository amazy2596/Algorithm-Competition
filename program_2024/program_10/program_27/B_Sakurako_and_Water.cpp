#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int d = 0; d < n; d++)
    {
        int mn1 = 0, mn2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + d < n)
            {
                mn1 = min(mn1, a[i][i + d]);
                mn2 = min(mn2, a[i + d][i]);
            }
        }
        ans += -(mn1 + mn2);
        if (d == 0)
            ans += mn1;
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