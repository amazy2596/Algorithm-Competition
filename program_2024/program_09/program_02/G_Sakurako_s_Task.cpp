#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int g = 0, mx = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], g = __gcd(g, a[i]), mx = max(mx, a[i]);
    if (n == 1)
    {
        cout << k - (a[1] >= k) << "\n";
        return;
    }
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        v[i] = (i - 1) * g;
    v[0] = -1;
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        int dx = v[i] - v[i - 1] - 1;
        if (k > dx)
        {
            k -= dx;
            ans = v[i];
        }
        else 
            break;
    }
    ans += k;
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