#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = 0;
    vector ans(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        if (m % k == 0)
        {
            for (int j = i, num = 0; num < m; j++, num++)
            {
                ans[i][j % m] = cnt++ % k + 1;
            }
        }
        else 
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = cnt++ % k + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " \n"[j == m - 1];
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