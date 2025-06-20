#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n << "\n";
        return;
    }
    int ans = 0;
    while (n)
    {
        ans += n % k;
        n /= k;
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