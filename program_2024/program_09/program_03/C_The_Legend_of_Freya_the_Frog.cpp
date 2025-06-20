#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    int a = x / k + (x % k != 0);
    int b = y / k + (y % k != 0);
    if (a == b)
        cout << a + b << "\n";
    else if (a > b)
        cout << max(a, b) * 2 - 1 << "\n";
    else 
        cout << max(a, b) * 2 << "\n";
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