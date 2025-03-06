#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }

    if (sum < n)
        cout << 0;
    else if (sum == n * m)
        cout << n;
    else 
        cout << sum - sum / n * n << "\n";
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