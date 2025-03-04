#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 15 == 0)
        cout << n / 15 * 3 + 1 << "\n";
    else if (n % 15 == 1)
        cout << n / 15 * 3 + 2 << "\n";
    else
        cout << n / 15 * 3 + 3 << "\n";
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