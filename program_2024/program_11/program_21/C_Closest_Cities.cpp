#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), l(n + 2), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int mn = (i == 1 ? 0 : 1);
        if (i >= 3 && a[i - 1] - a[i - 2] < a[i] - a[i - 1])
            mn = a[i] - a[i - 1];
        r[i] = r[i - 1] + mn;
    }
    for (int i = n; i >= 1; i--)
    {
        int mn = (i == n ? 0 : 1);
        if (i <= n - 2 && a[i + 1] - a[i] > a[i + 2] - a[i + 1])
            mn = a[i + 1] - a[i];
        l[i] = l[i + 1] + mn;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
            cout << r[y] - r[x] << "\n";
        else
            cout << l[y] - l[x] << "\n";
    }
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