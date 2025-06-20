#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    if (n * p < k || n * (-p) > k)
        cout << -1 << "\n";
    else 
        cout << ceil(abs(k) * 1.0 / p) << "\n";
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