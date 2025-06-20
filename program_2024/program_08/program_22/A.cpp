#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double t1 = a / 100 * b + (100 - a) / 100;
    double t2 = c / 100 * d + (100 - c) / 100;
    if (t2 > t1)
        cout << "YES";
    else 
        cout << "NO";
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