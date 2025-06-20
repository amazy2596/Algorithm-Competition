#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector g(n + 1, vector<char>(n + 1));
    vector ans(n + 1, vector<int>(n + 1, INT32_MAX));
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        q.push({i, i});
        ans[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            if (i == j || g[i][j] == '-')
                continue;
            q.push({i, j});
            ans[i][j] = 1;
        }
    }

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 1; k <= n; k++)
        {
            for (int l = 1; l <= n; l++)
            {
                if (g[k][i] != '-' && g[j][l] != '-' && g[k][i] == g[j][l] && ans[k][l] == INT32_MAX)
                {
                    ans[k][l] = ans[i][j] + 2;
                    q.push({k, l});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (ans[i][j] == INT32_MAX ? -1 : ans[i][j]) << " ";
        }
        cout << "\n";
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