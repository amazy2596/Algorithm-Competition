#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT32_MAX));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int row = a[i], col = b[i];
        int sum = row + col;
        int cost = 0;
        for (int j = 0; j <= sum; j++)
        {
            for (int l = 0; l + j <= k; l++)
            {
                dp[i][j + l] = min(dp[i][j + l], dp[i - 1][l] + cost);
            }

            if (j < sum)
            {
                if (row >= col)
                    row--, cost += col;
                else 
                    col--, cost += row;
            }
        }
    }

    cout << (dp[n][k] == INT32_MAX ? -1 : dp[n][k]) << "\n";
    
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