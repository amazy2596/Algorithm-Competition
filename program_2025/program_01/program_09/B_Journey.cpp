#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int sum = a + b + c;
    int ans = n / sum * 3;
    n -= n / sum * sum;
    if (n > 0)
        n -= a, ans++;
    if (n > 0)
        n -= b, ans++;
    if (n > 0)
        n -= c, ans++;
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