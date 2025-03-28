#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    double l, x, y;
    cin >> l >> x >> y;
    if (x * x + y * y <= l * l)
    {
        cout << "Yes\n";
        cout << "0\n";
    }
    else if ((x - l) * (x - l) + y * y <= l * l)
    {
        cout << "Yes\n";
        cout << l << "\n";
    }
    else 
        cout << "No\n";
}
py

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}