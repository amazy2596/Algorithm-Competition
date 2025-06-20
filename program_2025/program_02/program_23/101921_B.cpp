#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[i + 1][j] < a[i][j] || a[i + 1][j + 1] < a[i][j])
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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