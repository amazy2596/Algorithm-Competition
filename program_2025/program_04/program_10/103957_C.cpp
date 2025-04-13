#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    if ((k - 1) * m < q || n < q)
    {
        cout << "No\n";
        return;
    }

    if ((n - q) % k != 0)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    // n - x * k == q;
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