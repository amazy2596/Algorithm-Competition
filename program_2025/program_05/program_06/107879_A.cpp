#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b || b == c)
    {
        cout << "NO\n";
        return;
    }

    if (b == 0)
    {
        if (a + c == 0)
            cout << "YES\n";
        else 
            cout << "NO\n";
        return;
    }

    if (a == c && c == 0)
        cout << "YES\n";
    else 
        cout << "NO\n";
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