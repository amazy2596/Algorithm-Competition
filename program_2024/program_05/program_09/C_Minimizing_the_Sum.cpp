#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<intt> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<intt>> dp(n + 1, vector<intt>(k + 1, 1e18));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                intt mn = 1e18;
                for (int d = 0; j + d <= k && i + d < n; d++)
                {
                    mn = min(mn, a[i + d]);
                    dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * mn);
                }
            }
        }
        cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
    }
    return 0;
}