#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, col;
        cin >> x >> y >> col;
        if (col <= n)
        {
            if (ceil(y * 1.0 / 2) != col)
            {
                cout << "No\n";
                return;
            }
        }
        else if (col <= 2 * n)
        {
            int cnt = 1 + (col - n - 1) * 2;
            if (x != col - cnt)
            {
                cout << "No\n";
                return;
            }
        }
        else
        {
            int mx = 2 * (x - 1) + 1;
            int cnt = col - 2 * n - 1;
            if (!(y == mx - cnt || y == mx - cnt - 1))
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