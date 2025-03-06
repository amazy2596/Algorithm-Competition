#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int l, n;
    cin >> l >> n;

    vector<int> row(n + 1), col(n + 1);
    vector g(n + 1, vector<int>(n + 1));
    int ans = 0;

    auto print = [&]()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cout << g[i][j] << " \n"[j == n];
        cout << "\n";
    };

    auto dfs = [&](auto dfs, int i, int j) -> void
    {
        if (j == n)
        {
            if (row[i] <= l)
            {
                int remain = l - row[i];
                col[j] += remain;
                row[i] += remain;
                g[i][j] = remain;
                dfs(dfs, i + 1, 1);
                g[i][j] = 0;
                row[i] -= remain;
                col[j] -= remain;
                // ans++;
                // for (int j = 1; j <= n; j++)
                    // cout << g[i][j] << " \n"[j == n];
            }
            return;
        }
        if (i == n)
        {
            bool f = 1;
            for (int j = 1; j <= n; j++)
            {
                if (col[j] > l)
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                ans++;
                // print();
            }
            return;
        }
        for (int x = 0; x <= l; x++)
        {
            if (row[i] + x > l || col[j] + x > l)
            {
                g[i][j] = 0;
                continue;
            }
            row[i] += x;
            col[j] += x;
            g[i][j] = x;
            dfs(dfs, i, j + 1);
            g[i][j] = 0;
            row[i] -= x;
            col[j] -= x;
        }
    };

    dfs(dfs, 1, 1);
    cout << ans << "\n";
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