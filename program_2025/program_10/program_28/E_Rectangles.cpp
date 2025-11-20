// Problem: E. Rectangles
// URL: https://codeforces.com/contest/2160/problem/E
// Author: amazy
// Date: 2025-10-28 19:13:11

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;
    bool rev = 0;
    vector<string> g;
    if (n > m)
    {
        vector<string> input(n + 1);
        g.resize(m + 1, string(n + 1, '0'));
        for (int i = 1; i <= n; i++)
        {
            cin >> input[i];
            input[i] = " " + input[i];
            for (int j = 1; j <= m; j++)
            {
                if (n > m) g[j][i] = input[i][j];
                else g[i][j] = input[i][j];
            }
        }
        swap(n, m);
        rev = 1;
    }
    else 
    {
        g.resize(n + 1);
        for (int i = 1; i <= n; i++) 
        {
            cin >> g[i];
            g[i] = " " + g[i];
        }
    }

    vector<vector<int>> ls(n + 1, vector<int>(n + 1, 1)), rs(n + 1, vector<int>(n + 1, 0)), ans(n + 1, vector<int>(m + 1));
    for (int j = 1; j <= m; j++)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, inf));
        for (int u = 1; u <= n; u++)
        {
            for (int d = u + 1; d <= n; d++)
            {
                if (ls[u][d] <= j && j <= rs[u][d])
                {
                    dp[u][d] = min(dp[u][d], (rs[u][d] - ls[u][d] + 1) * (d - u + 1));
                }
                if (g[u][j] == '1' && g[d][j] == '1')
                {
                    int tmp = max(j, rs[u][d]) + 1;
                    ls[u][d] = tmp - 1;
                    while (tmp <= m && !(g[u][tmp] == '1' && g[d][tmp] == '1')) tmp++;
                    if (tmp == m + 1) rs[u][d] = 0;
                    else rs[u][d] = tmp;
                }
                if (ls[u][d] <= j && j <= rs[u][d])
                {
                    dp[u][d] = min(dp[u][d], (rs[u][d] - ls[u][d] + 1) * (d - u + 1));
                }
            }
        }

        for (int len = n; len >= 1; len--)
        {
            for (int u = 1; u + len - 1 <= n; u++)
            {
                int d = u + len - 1;
                dp[u][d] = min({dp[u][d], dp[u - 1][d], dp[u][d + 1]});
                // dp[u - 1][d] = min(dp[u - 1][d], dp[u][d]);
                // dp[u][d + 1] = min(dp[u][d + 1], dp[u][d]);
            }
        }

        for (int i = 1; i <= n; i++) ans[i][j] = dp[i][i];
    }

    if (rev)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (ans[i][j] == inf) cout << "0 ";
                else cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else 
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ans[i][j] == inf) cout << "0 ";
                else cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main()
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