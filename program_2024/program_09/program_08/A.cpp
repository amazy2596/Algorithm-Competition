#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    long double n, m;    
    cin >> n >> m;
    cout << fixed << setprecision(12) << n / m << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}