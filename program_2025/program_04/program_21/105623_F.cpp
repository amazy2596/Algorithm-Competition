#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    int mx = 0;
    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            string t = s;
            for (int i = 0; i < n; i++)
            {
                if (i >= l && i <= r && t[i] == '?')
                    t[i] = 'v';
                else if (t[i] == '?')
                    t[i] = 'o';
            }

            array<int, 3> dp = {0, 0, 0};
            for (int i = 0; i < n; i++)
            {
                if (t[i] == 'o')
                    dp[0]++, dp[2] += dp[1];
                else if (t[i] == 'v')
                    dp[1] += dp[0];
            }

            mx = max(mx, dp[2]);
        }
    }

    cout << mx << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}