#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    while (true)
    {
        if (n >= a)
            n -= a, ans++;
        else if (n >= b)
            n -= b, ans++;
        else if (n >= c)
            n -= c, ans++;
        else
            break;
    }
    cout << ans << "\n";
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