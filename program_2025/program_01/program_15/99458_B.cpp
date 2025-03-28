#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k < max(n, m))
    {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> ans(n, vector<int>(m));
    int i = 0, j = 0;
    while (k--)
    {
        ans[i][j]++;
        i = (i + 1) % n;
        j = (j + 1) % m;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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