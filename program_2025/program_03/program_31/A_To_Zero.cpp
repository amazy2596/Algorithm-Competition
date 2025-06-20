#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int odd = (k % 2 == 0 ? k - 1 : k), even = (k % 2 == 0 ? k : k - 1);
    if (n % 2 == 0)
        cout << (int)ceil(n * 1.0 / even) << "\n";
    else 
        cout << 1 + (int)ceil((n - odd) * 1.0 / even) << "\n";
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