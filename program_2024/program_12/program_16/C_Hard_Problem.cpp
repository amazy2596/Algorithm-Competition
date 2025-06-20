#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int ans = min(m, a) + min(m, b);
    int remain = max(0ll, m - a) + max(0ll, m - b);
    ans += min(remain, c);
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