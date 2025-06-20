#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int u_mx = -1e10, u_mn = 1e10, v_mn = 1e10, v_mx = -1e10;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        u_mx = max(u_mx, x + y);
        u_mn = min(u_mn, x + y);
        v_mx = max(v_mx, x - y);
        v_mn = min(v_mn, x - y);
    }
    int ans = 1e10;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        int s = a + b, j = a - b;
        ans = min(ans, max({u_mx - s, s - u_mn, v_mx - j, j - v_mn}));
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