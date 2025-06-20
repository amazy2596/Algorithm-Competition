#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector b(m + 1, vector<string>(n + 1));
    vector<bool> f(n + 1, false);
    int mx = 0;
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
            cnt += (b[i][j] == a[j]);
            f[j] = f[j] | (b[i][j] == a[j]);
        }

        mx = max(mx, cnt);
    }

    bool ok = 1;
    for (int i = 0; i < n; i++)
        ok &= f[i];
    
    if (!ok)
    {
        cout << "-1\n";
        return;
    }

    cout << n + (n - mx) * 2 << "\n";
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