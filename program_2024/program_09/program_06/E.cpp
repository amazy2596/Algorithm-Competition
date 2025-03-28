#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1e9;
    sort(a.begin(), a.end());
    for (int m = 0; m < n; m++)
    {
        int cur = m;
        int idx = 1;
        while (idx <= n)
        {
            cur++;
            auto it = upper_bound(a.begin() + 1, a.end(), a[idx] + m);
            idx = it - a.begin();
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
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