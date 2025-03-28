#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x, y, z, t;
    cin >> n >> x >> y >> z >> t;
    vector<int> a(n), b(n), c(n);
    int ans = x + y;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if (z + t >= c[i])
            ans = max(ans, a[i] + b[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}