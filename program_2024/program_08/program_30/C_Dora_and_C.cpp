#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int d = __gcd(a, b);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] %= d;
    }
    sort(v.begin(), v.end());
    int ans = v[n - 1] - v[0];
    for (int i = 1; i < n; i++)
        ans = min(ans, v[i - 1] + d - v[i]);
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