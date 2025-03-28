#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    while (n > 1 && m)
    {
        m--;
        int mn = n;
        mn = min(mn, (int)ceil(sqrt(n)));
        mn = min(mn, n - 1);
        mn = min(mn, (int)ceil(n * 1.0 / 2));

        n = mn;
    }

    cout << n - m << "\n";
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