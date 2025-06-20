#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    map<pair<int, int>, int> mp1, mp2;
    int i = 0, j = 0;
    while (i < n)
    {
        int x = i, y = j, sum = 0;
        while (x < n && y < m)
        {
            sum += a[x][y];
            x++, y++;
        }
        x = i, y = j;
        while (x < n && y < m)
        {
            mp1[{x, y}] = sum;
            x++, y++;
        }
        i++;
    }
    i = 0, j = 1;
    while (j < m)
    {
        int x = i, y = j, sum = 0;
        while (x < n && y < m)
        {
            sum += a[x][y];
            x++, y++;
        }
        x = i, y = j;
        while (x < n && y < m)
        {
            mp1[{x, y}] = sum;
            x++, y++;
        }
        j++;
    }

    i = 0, j = 0;
    while (j < m)
    {
        int x = i, y = j, sum = 0;
        while (x < n && y >= 0)
        {
            sum += a[x][y];
            x++, y--;
        }
        x = i, y = j;
        while (x < n && y >= 0)
        {
            mp2[{x, y}] = sum;
            x++, y--;
        }
        j++;
    }

    i = 0, j = m - 1;
    while (i < n)
    {
        int x = i, y = j, sum = 0;
        while (x < n && y >= 0)
        {
            sum += a[x][y];
            x++, y--;
        }
        x = i, y = j;
        while (x < n && y >= 0)
        {
            mp2[{x, y}] = sum;
            x++, y--;
        }
        i++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // int mn = min(i, j);
            // int x = i - mn, y = j - mn;
            // cout << mp1[{x, y}] << "\n";
            int sum = mp1[{i, j}] + mp2[{i, j}] - a[i][j];
            ans = max(ans, sum);
        }
    }

    cout << ans << "\n";
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