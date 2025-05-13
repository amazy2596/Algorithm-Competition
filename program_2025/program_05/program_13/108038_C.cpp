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
    {
        cin >> a[i];
        pre[i] = max(pre[i - 1], a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] > a[i])
            ans = max(ans, pre[i] + a[i]);
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