#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector ans(n + 1, vector<int>(m + 1));
    if ((n + m) % 4 != 3)
    {
        cout << "-1\n";
        return;
    }
    int x = 0;
    for (int i = 1; i < n; i++)
        ans[i][m] = i, x ^= i;
    for (int j = 1; j < m; j++)
        ans[n][j] = n + j;
    
    ans[n][m] = x ^ (n + m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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