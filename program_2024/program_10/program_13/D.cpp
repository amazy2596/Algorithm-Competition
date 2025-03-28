#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x;
    cin >> x;
    int ans = x + 3;
    if (ans == 0)
    {
        ans = x + 1;
        cout << "1 1 3\n";
        cout << "1 2 1\n";
        cout << "1 2 " << ans;
    }
    else
    {
        cout << "1 1 3\n";
        cout << "1 2 3\n";
        cout << "1 2 " << ans;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}