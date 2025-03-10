#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int mx = 0;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        mx = max(mx, a);
    }

    cout << n * (mx - m) << "\n";
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