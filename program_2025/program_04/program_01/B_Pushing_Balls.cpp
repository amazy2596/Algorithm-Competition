#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '1')
            {
                bool f1 = 1, f2 = 1;
                for (int x = 0; x < i; x++)
                {
                    if (g[x][j] != '1')
                    {
                        f1 = 0;
                        break;
                    }
                }

                for (int y = 0; y < j; y++)
                {
                    if (g[i][y] != '1')
                    {
                        f2 = 0;
                        break;
                    }
                }

                if (!f1 && !f2)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
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