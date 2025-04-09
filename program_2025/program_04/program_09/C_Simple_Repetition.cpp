#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, k;
    cin >> x >> k;
    if (k >= 2)
    {
        cout << "NO\n";
        return;
    }

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}