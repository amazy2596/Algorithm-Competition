#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    int ans = 0, remain = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (ans / 2 + a[i] / 2 <= r)
        {
            ans += a[i] / 2 * 2;
            remain += a[i] % 2;
        }
    }
    r -= ans / 2;
    if (r < remain)
    {
        r *= 2;
        r -= remain;
        ans += (r > 0 ? r : 0);
    }
    else
        ans += remain;
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