#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i], g[i] = " " + g[i];

    vector<array<int, 4>> ans;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j + 1 <= m; j++)
        {
            if (g[i][j] == '0')
            {
                g[i][j] = '1';
                g[i][j + 1] = (g[i][j + 1] == '1' ? '0' : '1');
                ans.push_back({i, j, i, j + 1});
            }
        }
    }

    for (int i = 1; i + 1 <= n; i++)
    {
        if (g[i][m] == '0')
        {
            g[i][m] = '1';
            g[i + 1][m] = (g[i + 1][m] == '1' ? '0' : '1');
            ans.push_back({i, m, i + 1, m});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '0')
            {
                cout << "-1\n";
                return;
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
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