#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    int mn = (n - 1) * x + 1, mx = mn + (x - 1) * 2;
    if (k >= mn && k <= mx)
    {
        int l = x, r = l + (n - 1) * x;
        int cnt = k - (r - l + 1);
        r += cnt / 2;
        l -= cnt - (cnt / 2);

        cout << l << " " << r;
    }
    else
        cout << -1;
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