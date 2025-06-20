#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "YES\n";
        cout << 2 << " " << 3 << "\n";
    }
    else if (n == 2)
        cout << "NO\n";
    else 
    {
        cout << "YES\n";
        cout << n - 1 << " " << n << "\n";
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