#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), lmx(n), rmx(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        lmx[i] = mx;
    }
    mx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        mx = max(mx, a[i]);
        rmx[i] = mx;
    }
    if (n == 1)
    {
        cout << mx << "\n";
        return ;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = max(i + 1, n - (k - i) - 1);
        if (j >= n)
            continue;
        ans = max(ans, lmx[i] + rmx[j]);
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