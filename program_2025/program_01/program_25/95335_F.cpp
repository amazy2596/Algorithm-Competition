#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a + b + c < n)
    {
        cout << "No\n";
        return;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int k = n - i - j;
            if (k >= 0)
            {
                if (i + j >= a && j + k >= b && k + i >= c)
                {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }

    cout << "No\n";
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