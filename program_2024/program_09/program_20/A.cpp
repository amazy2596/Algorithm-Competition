#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m = n - k;
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans += a[i];
    int cur = ans;
    for (int i = 1; i + m - 1 < n; i++)
    {
        cur -= a[i - 1];
        cur += a[i + m - 1];
        ans = max(ans, cur);
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