#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int cnt = n - m;
    if (r >= cnt)
        r -= cnt, cnt = 0;
    else 
        cnt -= r, r = 0;

    if (cnt)
        l += cnt;

    cout << l << " " << r << "\n";
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