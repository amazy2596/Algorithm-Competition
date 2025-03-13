#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }

    if (sum % x == 0 && sum / x == n)
        cout << "YES\n";
    else 
        cout << "NO\n";
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