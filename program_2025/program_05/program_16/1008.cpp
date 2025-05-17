#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>(m + 1)), pre(n + 1, vector<int>(m + 1)), suf(n + 1, vector<int>(m + 2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            pre[i][j] = max(pre[i][j - 1], g[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            suf[i][j] = max(suf[i][j + 1], g[i][j]);
        }
    }

    int ans = 0;
    for (int k = 1; k <= m; k++)
    {
        int base = 0;
        vector<int> best(n + 1);
        for (int i = 1; i <= n; i++)
            best[i] = max(pre[i][k - 1], suf[i][k + 1]), base += best[i];
        
        vector<int> delta;
        for (int i = 1; i <= n; i++)
            delta.push_back(g[i][k] - best[i]);

        sort(delta.rbegin(), delta.rend());
        delta.insert(delta.begin(), 0);

        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            total += delta[i];
            if (i > n / 2)
                ans = max(ans, base + total);
        }
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}