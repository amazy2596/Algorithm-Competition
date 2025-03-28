#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        int cur = 0;
        while (!vis[i])
        {
            cur += s[i] == '0';
            vis[i] = 1;
            i = a[i];
        }
        while (vis[i] != -1)
        {
            vis[i] = -1;
            f[i] = cur;
            i = a[i];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
    cout << "\n";
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