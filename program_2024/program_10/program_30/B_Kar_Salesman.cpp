#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        mx = max(mx, t);
        sum += t;
    }
    cout << max((int)ceil(sum * 1.0 / x), mx) << "\n";
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