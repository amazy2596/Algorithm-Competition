#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (a[i][0] == 1 && a[i][1] == 1)
            ans += n - 2;
        if (i == 0 || i == n)
            continue;
        if (a[i][0] == 1 && a[i - 1][1] == 1 && a[i + 1][1] == 1)
            ans++;
        if (a[i][1] == 1 && a[i - 1][0] == 1 && a[i + 1][0] == 1)
            ans++;
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