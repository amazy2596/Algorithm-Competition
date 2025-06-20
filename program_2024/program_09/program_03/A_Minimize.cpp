#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = 1e9;
    for (int i = a; i <= b; i++)
        ans = min(ans, (i - a) + (b - i));
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