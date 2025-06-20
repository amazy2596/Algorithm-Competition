#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int x = n - k + 1, y = n;
    if (x % 2 == 1 && y % 2 == 1)
    {
        int cnt = (y - x + 1) / 2 + 1;
        if (cnt % 2 == 0)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    else
    {
        int cnt = (y - x + 1) / 2;
        if (cnt % 2 == 0)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
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