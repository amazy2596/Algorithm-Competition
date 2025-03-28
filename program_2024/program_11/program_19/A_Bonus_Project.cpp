#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, num = 0;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        num += a[i] / b[i];
    }
    if (num < k)
    {
        for (int i = 1; i <= n; i++)
            cout << 0 << " \n"[i == n];
        return;
    }
    vector<int> ans(n + 1);
    for (int i = n; i >= 1; i--)
        ans[i] = min(k, a[i] / b[i]), k -= ans[i];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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