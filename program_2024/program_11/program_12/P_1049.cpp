#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int v, n;
    cin >> v >> n;
    vector<int> dp(v + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = v; j - x >= 0; j--)
            dp[j] = max(dp[j], dp[j - x] + x);
    }
    cout << v - dp[v] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}