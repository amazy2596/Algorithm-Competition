#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int mn = 1e10;
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin >> x;
        mn = min(mn, x);
    }
    cout << mn;
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