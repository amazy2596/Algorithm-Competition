#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int x = i;
        bool f = 1;
        for (int j = 1; x; j++)
        {
            int t = x % 10;
            x /= 10;
            if (j % 2 == 1)
            {
                if (t % 2 == 0)
                    f = 0;
            }
            else 
            {
                if (t % 2 == 1)
                    f = 0;
            }
        }
        ans += f;
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