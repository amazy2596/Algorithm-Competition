#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1));
    vector b(n + 1, vector<int>(m + 1));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
        for (int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
            if (a[i][j] == 7)
                ans += b[i][j];
            else if (a[i][j] == 77)
                ans += 2 * b[i][j];
            else if (a[i][j] == 777)
                ans += 3 * b[i][j];
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}