#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    int ans = 1;
    if (sum % mx == 0)
        ans = sum / mx;
    if ((sum + k) / mx > sum / mx)
        ans = min((sum + k) / mx, n);
    for (int i = sum / mx; i >= 1; i--)
    {
        if (sum % i == 0 || sum % i + k >= i)
            ans = max(ans, i);
    }
    cout << ans << '\n';
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