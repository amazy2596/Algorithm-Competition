#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    string target = "narek";
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> dp(5, -1e9), cur;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cur = dp;
        for (int j = 0; j < 5; j++)
        {
            if (dp[j] == -1e9)
                continue;
            int score = 0, next = j;
            for (int k = 0; k < m; k++)
            {
                int idx = target.find(s[i][k]);
                if (idx == -1)
                    continue;
                if (idx == next)
                {
                    score++;
                    next = (next + 1) % 5;
                }
                else 
                    score--;
            }
            cur[next] = max(cur[next], dp[j] + score);
        }
        dp = cur;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans = max(ans, dp[i] - 2 * i);
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