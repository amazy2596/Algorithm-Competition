#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    // 0
    // 1 2 
    // 3 4 5 6
    // 7 8
    int ans = 0;
    while (n)
    {
        int mod = n / 2 + 1;
        n %= mod;
        ans++;
    }
    cout << ans << "\n";
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