#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a % 2 == 0 && b != 0)
    {
        if (d % 2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else 
    {
        if (c % 2 == 0)
        {
            if (d % 2 == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            if (d % 2 == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
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