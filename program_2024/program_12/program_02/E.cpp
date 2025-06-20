#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        int pair = (n - 1) / 2;
        cout << (pair % 2 == 0 ? (0 ^ (n + 1)) : (1 ^ (n + 1))) << "\n";
    }
    else
    {
        int pair = n / 2;
        cout << (pair % 2 == 0 ? 0 : 1) << "\n";
    }
}
// 011 2
// 010 3
// 101 4
// 100 5

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