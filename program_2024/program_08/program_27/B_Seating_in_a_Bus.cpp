#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n; 
    vector<int> a(n);
    vector<bool> vis(2e5 + 10, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            vis[a[i]] = 1;
        else 
        {
            if (!vis[a[i] - 1] && !vis[a[i] + 1])
            {
                cout << "NO\n";
                return;
            }
            vis[a[i]] = 1;
        }
    }
    cout << "YES\n";
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