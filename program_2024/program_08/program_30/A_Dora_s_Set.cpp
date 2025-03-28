#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; )
    {
        if (i % 2 == 1 && (i + 1) % 2 == 0 && (i + 2) % 2 == 1 && (i + 2) <= r)
        {
            ans++;
            i += 4;
        }
        else 
            i++;
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