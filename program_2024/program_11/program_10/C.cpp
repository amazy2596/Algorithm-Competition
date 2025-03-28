#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    string z = to_string(c);
    int ans = 0;
    for (int i = 0; i <= c; i++)
    {
        string x = to_string(i), y = to_string(c - i);
        if (x.length() + y.length() + z.length() + 2 == n)
            ans++;
    }
    cout << ans << "\n";
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