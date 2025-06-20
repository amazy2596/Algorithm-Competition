#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        sum += d[i];
    }

    if (sum % 2 == 1)
    {
        cout << -1 << "\n";
        return;
    }

    int cnt = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = d[i]; j <= sum; j++)
        {
            dp[i][j] |= dp[i - 1][j - d[i]];
        }
    }

    if (!dp[n][cnt])
    {
        cout << -1 << "\n";
        return;
    }

    vector<int> u, v;
    int val = cnt;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i][val] == dp[i - 1][val])
        {
            u.push_back(i);
        }
        else 
        {
            v.push_back(i);
            val -= d[i];
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < u.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            while (d[u[i]] > 0 && d[v[j]] > 0)
            {
                d[u[i]]--, d[v[j]]--;
                ans.push_back({u[i], v[j]});
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto [u, v] : ans)
        cout << u << " " << v << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}