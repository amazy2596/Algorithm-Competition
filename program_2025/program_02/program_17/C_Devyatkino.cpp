#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    int ans = 1e9;
    int x = 9;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            int t = n + x * j;
            while (t != 0)
            {
                if (t % 10 == 7)
                {
                    ans = min(ans, j);
                    break;
                }

                t /= 10;
            }
        }

        x = x * 10 + 9;
    }

    cout << ans << "\n";
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