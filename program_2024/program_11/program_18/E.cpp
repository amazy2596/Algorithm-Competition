#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    const int N = 100000;
    vector<vector<int>> dp(n + 1, vector<int>(N + 1, 0)), pos(n + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= 17; k++)
        {
            int temp = a[i] >> k;
            for (int j = N; j >= temp; j--)
            {
                if (dp[i][j] == 0 && dp[i - 1][j - temp] != 0)
                    pos[i][j] = j - temp;
                dp[i][j] |= dp[i - 1][j - temp];
            }
        }
    }
    if (dp[n][N] == 0)
    {
        cout << -1;
        return;
    }
    vector<int> ans(n + 1);
    int last = N;
    for (int i = n; i >= 1; i--)
    {
        int temp = last - pos[i][last];
        last = pos[i][last];
        while (a[i] != temp)
            a[i] /= 2, ans[i]++;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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