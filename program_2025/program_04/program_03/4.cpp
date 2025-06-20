#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int ans = 0;
    int i = 0, j = 0;
    int di = 1, dj = 1;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            b[j] += b[j + dj];
            // b.erase(b.begin() + j + 1);
            dj++;
            ans++;
        }
        else if (a[i] < b[j])
        {
            a[i] += a[i + di];
            // a.erase(a.begin() + i + 1);
            di++;
            ans++;
        }
        else 
        {
            i += di;
            j += dj;
            di = dj = 1;
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