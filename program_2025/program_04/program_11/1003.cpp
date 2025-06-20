#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        c[i] += a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        c[i] += b[i];
    }

    int ans = 0;
    int l = 1;
    while (l <= n)
    {
        int r = l;
        while (r <= n && c[l] == c[r])
            r++;
        ans = max(ans, (pre[r - 1] - pre[l - 1]) * (r - l));
        l = r;
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