#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << __gcd(i, j) << " ";
    //     }
    //     cout << endl;
    // }
    if (n == 1)
        cout << 0 << "\n";
    else if (n == 2)
        cout << 2 << "\n";
    else if (n == 3)
        cout << 4 << "\n";
    else if (n % 2 == 0)
        cout << 4 << "\n";
    else if (n % 2 == 1)
        cout << 6 << "\n";
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