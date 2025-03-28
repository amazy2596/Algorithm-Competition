#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> lose(n + 1), win(n + 1), u(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> u[i];
    vector<int> dp(x + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if (j >= u[i])
                dp[j] = max(dp[j] + lose[i], dp[j - u[i]] + win[i]);
            else
                dp[j] += lose[i];
        }
    }
    cout << 5 * dp[x] << "\n";
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