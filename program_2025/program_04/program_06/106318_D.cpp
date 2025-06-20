#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x;
    cin >> x;

    for (int i = 0; i <= 31; i++)
    {
        if (((x >> i) & 1) == 0 && (1ll << i) < x)
        {
            cout << (1ll << i) << "\n";
            return;
        }
    }

    cout << "-1\n";
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