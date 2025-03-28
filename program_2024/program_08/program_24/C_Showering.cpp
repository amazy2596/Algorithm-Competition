#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (l[i] >= s)
            {
                cout << "YES\n";
                return;
            }
        }
        if (i == n - 1)
        {
            if ((m - r[i]) >= s)
            {
                cout << "YES\n";
                return;
            }
        }
        if (i)
        {
            if (l[i] - r[i - 1] >= s)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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