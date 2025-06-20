#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0 && b % 2 == 0)
        cout << "YES\n";
    else if (a % 2 == 0 && b % 2 == 1)
    {
        if (a >= 2)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    else
        cout << "NO\n";
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