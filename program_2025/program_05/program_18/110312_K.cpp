#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    string a, b, c;
    cin >> a >> b >> c;
    if (a[0] == 'M' && b[0] == 'S' && c[0] == 'T')
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