#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, n;
    cin >> x >> n;
    int ans = 0;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            if (x > (n - 1) * i && (x - (n - 1) * i) % i == 0)
                ans = max(ans, i);
            int j = x / i;
            if (x > (n - 1) * j && (x - (n - 1) * j) % j == 0)
                ans = max(ans, j);
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}