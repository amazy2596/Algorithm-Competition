#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int s, k;
    cin >> s >> k;
    if (s % k == 0)
    {
        cout << k << "\n";
        return;
    }
    if (s > k * k)
    {
        cout << max(1ll, k - 2) << "\n";
        return;
    }
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