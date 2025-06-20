#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y, n;
    cin >> x >> y >> n;
    if (n >= x + y)
        cout << "YES";
    else 
        cout << "NO";
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