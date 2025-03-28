#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = n;
    for (int i = 0; i <= 30; i++)
    {
        int x = n % (1 << (i + 1));
        int d = 1e10;
        if (x >= (1 << i))
            ans |= 1 << i;
        else
        {
            if (n >= 1 << i)
            {
                int l = x + 1;
                int r = (1 << i) - x;
                d = min(l, r);
            }
            else 
                d = min(d, (1 << i) - x);
        }
        if (d <= m)
            ans |= 1 << i;
    }
    cout << ans << "\n";
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