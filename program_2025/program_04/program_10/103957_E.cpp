#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    const int MAXN = 1e4 + 10;
    vector<vector<int>> dp(MAXN);
    vector<vector<pair<int, int>>> from(MAXN);

    dp[0].assign(MAXN, false);
    from[0].assign(MAXN, {});
    for (int i = 1; i < MAXN; ++i) 
    {
        dp[i].resize(MAXN / i + 10, 0);
        from[i].resize(MAXN / i + 10);
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = MAXN - 1; j >= 0; j--)
        {
            for (int k = dp[j].size() - 1; k >= 0; k--)
            {
                if (j >= c[i] && dp[j - c[i]][k] && !dp[j][k])
                {
                    dp[j][k] = 1;
                    from[j][k] = {j - c[i], k};
                }
                if (k >= c[i] && dp[j][k - c[i]] && !dp[j][k])
                {
                    dp[j][k] = 1;
                    from[j][k] = {j, k - c[i]};
                }
            }
        }
    }
    
    while (m--)
    {
        int k;
        cin >> k;

        bool f = 0;
        for (int j = 1; j * j <= k && !f; j++)
        {
            if (k % j == 0)
            {
                if (dp[j][k / j])
                {
                    f = 1;
                    int x = j, y = k / j;
                    vector<int> a, b;
                    while (x > 0 || y > 0)
                    {
                        auto [last_x, last_y] = from[x][y];
                        if (x != last_x)
                            a.push_back(x - last_x);
                        if (y != last_y)
                            b.push_back(y - last_y);
                        x = last_x;
                        y = last_y;
                    }

                    cout << "Yes\n";
                    cout << a.size() << " " << b.size() << "\n";
                    for (int i = 0; i < a.size(); i++)
                        cout << a[i] << " \n"[i == a.size() - 1];
                    for (int i = 0; i < b.size(); i++)
                        cout << b[i] << " \n"[i == b.size() - 1];
                }
            }
        }

        if (!f) cout << "No\n";

        // auto dfs = [&](auto dfs, int x, int y) -> bool
        // {
        //     if (x == 0 && y == 0)
        //         return true;
            
        //     for (auto [last_x, last_y] : from[{x, y}])
        //     {
        //         int dx = x - last_x, dy = y - last_y;
        //         if (dx && count[dx] > 0)
        //         {
        //             count[dx]--;
        //             a.push_back(dx);
        //             if (dfs(dfs, last_x, last_y))
        //                 return true;
        //             a.pop_back();
        //             count[dx]++;
        //         }

        //         if (dy && count[dy] > 0)
        //         {
        //             count[dy]--;
        //             b.push_back(dy);
        //             if (dfs(dfs, last_x, last_y))
        //                 return true;
        //             b.pop_back();
        //             count[dy]++;
        //         }
        //     }

        //     return false;
        // };
    }
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