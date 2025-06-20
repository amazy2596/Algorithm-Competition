#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int mn = 1e9, mx = -1e9;
            for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
            {
                int nx = i + dx, ny = j + dy;
                mn = min(mn, a[nx][ny]);
                mx = max(mx, a[nx][ny]);
            }
            if (a[i][j] < 0 && a[i][j] < mn)
                a[i][j] = mn;
            if (a[i][j] > 0 && a[i][j] > mx)
                a[i][j] = mx;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != 0)
            {
                cout << "NO\n";
                return;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}