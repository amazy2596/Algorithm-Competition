#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << (n + min(x, y) - 1) / min(x, y) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}