#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i++)
        cin >> a[i];
    priority_queue<int> q;
    // vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x = min({k, i, n - i + 1, n - k + 1});
            int y = min({k, j, m - j + 1, m - k + 1});
            // g[i][j] = x * y;
            q.push(x * y);
        }
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = w - 1; i >= 0; i--)
    {
        ans += a[i] * q.top();
        q.pop();
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